#pragma once

#include <cstdint>
#include <string>

class LibraryIndexStore {
 public:
  static LibraryIndexStore& getInstance();

  void touchPath(const std::string& path);
  uint32_t getAddedOrder(const std::string& path) const;

 private:
  LibraryIndexStore() = default;
  void ensureLoaded();
  bool loadFromFile();
  bool saveToFile() const;
};

#define LIBRARY_INDEX LibraryIndexStore::getInstance()
