#pragma once

#include <string>
#include <vector>

namespace BionicReading {
struct Segment {
  std::string text;
  bool bold = false;
};

bool splitWord(const std::string& word, std::string& prefix, std::string& suffix);
void splitLine(const std::string& line, std::vector<Segment>& outSegments);
}  // namespace BionicReading

