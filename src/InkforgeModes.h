#pragma once

#include "CrossPointSettings.h"

namespace InkforgeModes {
void applyReaderPreset(CrossPointSettings& settings, uint8_t preset);
void applyRefreshMode(CrossPointSettings& settings, uint8_t refreshMode);
void applyPerformanceMode(CrossPointSettings& settings, uint8_t performanceMode);
void applyControlProfile(CrossPointSettings& settings, uint8_t controlProfile);
}  // namespace InkforgeModes
