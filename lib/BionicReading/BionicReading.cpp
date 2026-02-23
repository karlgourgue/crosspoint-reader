#include "BionicReading.h"

#include <algorithm>
#include <cctype>

namespace BionicReading {
namespace {
bool isAsciiWordChar(const unsigned char c) { return std::isalnum(c) || c == '\''; }

size_t focusLenForAsciiWord(const size_t len) {
  if (len <= 1) return len;
  const size_t approx = (len * 2 + 4) / 5;  // ~40%
  return std::clamp<size_t>(approx, 1, 4);
}
}  // namespace

bool splitWord(const std::string& word, std::string& prefix, std::string& suffix) {
  prefix.clear();
  suffix.clear();
  if (word.empty()) return false;

  const bool asciiOnly = std::all_of(word.begin(), word.end(),
                                     [](const char ch) { return static_cast<unsigned char>(ch) < 0x80; });
  if (!asciiOnly) return false;

  const bool hasAlphaNum = std::any_of(word.begin(), word.end(), [](const char ch) {
    return std::isalnum(static_cast<unsigned char>(ch));
  });
  if (!hasAlphaNum) return false;

  size_t start = 0;
  while (start < word.size() && !isAsciiWordChar(static_cast<unsigned char>(word[start]))) {
    ++start;
  }
  if (start >= word.size()) return false;

  size_t end = word.size();
  while (end > start && !isAsciiWordChar(static_cast<unsigned char>(word[end - 1]))) {
    --end;
  }
  if (end <= start) return false;

  const size_t coreLen = end - start;
  if (coreLen <= 1) return false;
  const size_t focus = focusLenForAsciiWord(coreLen);

  prefix = word.substr(0, start + focus);
  suffix = word.substr(start + focus);
  return !prefix.empty() && !suffix.empty();
}

void splitLine(const std::string& line, std::vector<Segment>& outSegments) {
  outSegments.clear();
  if (line.empty()) return;

  size_t i = 0;
  while (i < line.size()) {
    const unsigned char c = static_cast<unsigned char>(line[i]);
    if (c < 0x80 && isAsciiWordChar(c)) {
      const size_t start = i;
      while (i < line.size() && static_cast<unsigned char>(line[i]) < 0x80 &&
             isAsciiWordChar(static_cast<unsigned char>(line[i]))) {
        ++i;
      }
      const std::string word = line.substr(start, i - start);
      std::string prefix;
      std::string suffix;
      if (splitWord(word, prefix, suffix)) {
        outSegments.push_back({prefix, true});
        outSegments.push_back({suffix, false});
      } else {
        outSegments.push_back({word, false});
      }
    } else {
      const size_t start = i;
      while (i < line.size()) {
        const unsigned char n = static_cast<unsigned char>(line[i]);
        if (n < 0x80 && isAsciiWordChar(n)) {
          break;
        }
        ++i;
      }
      outSegments.push_back({line.substr(start, i - start), false});
    }
  }
}
}  // namespace BionicReading

