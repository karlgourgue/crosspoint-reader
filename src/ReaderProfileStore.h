#pragma once

#include <string>

namespace ReaderProfileStore {
bool loadForCachePath(const std::string& cachePath);
bool saveForCachePath(const std::string& cachePath);
}  // namespace ReaderProfileStore
