#include "LibraryIndexStore.h"

#include <HalStorage.h>
#include <Serialization.h>

#include <vector>

namespace {
constexpr char INDEX_FILE[] = "/.crosspoint/library_index.bin";
constexpr uint8_t INDEX_VERSION = 1;

struct Entry {
  std::string path;
  uint32_t order = 0;
};

std::vector<Entry> entries;
uint32_t nextOrder = 1;
bool loaded = false;
}  // namespace

LibraryIndexStore& LibraryIndexStore::getInstance() {
  static LibraryIndexStore instance;
  return instance;
}

void LibraryIndexStore::ensureLoaded() {
  if (loaded) {
    return;
  }
  loadFromFile();
  loaded = true;
}

bool LibraryIndexStore::loadFromFile() {
  FsFile inputFile;
  if (!Storage.openFileForRead("LIS", INDEX_FILE, inputFile)) {
    return false;
  }

  uint8_t version = 0;
  serialization::readPod(inputFile, version);
  if (version != INDEX_VERSION) {
    inputFile.close();
    return false;
  }

  uint16_t count = 0;
  serialization::readPod(inputFile, count);
  entries.clear();
  entries.reserve(count);

  uint32_t maxOrder = 0;
  for (uint16_t i = 0; i < count; ++i) {
    Entry e;
    serialization::readString(inputFile, e.path);
    serialization::readPod(inputFile, e.order);
    if (!e.path.empty()) {
      entries.push_back(std::move(e));
      if (entries.back().order > maxOrder) {
        maxOrder = entries.back().order;
      }
    }
  }
  nextOrder = maxOrder + 1;

  inputFile.close();
  return true;
}

bool LibraryIndexStore::saveToFile() const {
  Storage.mkdir("/.crosspoint");

  FsFile outputFile;
  if (!Storage.openFileForWrite("LIS", INDEX_FILE, outputFile)) {
    return false;
  }

  serialization::writePod(outputFile, INDEX_VERSION);
  serialization::writePod(outputFile, static_cast<uint16_t>(entries.size()));
  for (const auto& e : entries) {
    serialization::writeString(outputFile, e.path);
    serialization::writePod(outputFile, e.order);
  }
  outputFile.close();
  return true;
}

void LibraryIndexStore::touchPath(const std::string& path) {
  ensureLoaded();
  for (auto& e : entries) {
    if (e.path == path) {
      return;
    }
  }
  entries.push_back({path, nextOrder++});
  saveToFile();
}

uint32_t LibraryIndexStore::getAddedOrder(const std::string& path) const {
  for (const auto& e : entries) {
    if (e.path == path) {
      return e.order;
    }
  }
  return 0;
}
