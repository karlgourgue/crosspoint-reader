#include "ReaderProfileStore.h"

#include <HalStorage.h>
#include <Serialization.h>

#include "CrossPointSettings.h"

namespace ReaderProfileStore {
namespace {
constexpr uint8_t PROFILE_VERSION = 1;
constexpr char PROFILE_FILE[] = "/reader_profile.bin";

std::string profilePathFor(const std::string& cachePath) { return cachePath + PROFILE_FILE; }
}  // namespace

bool loadForCachePath(const std::string& cachePath) {
  FsFile inputFile;
  if (!Storage.openFileForRead("RPS", profilePathFor(cachePath), inputFile)) {
    return false;
  }

  uint8_t version = 0;
  serialization::readPod(inputFile, version);
  if (version != PROFILE_VERSION) {
    inputFile.close();
    return false;
  }

  serialization::readPod(inputFile, SETTINGS.readerPreset);
  serialization::readPod(inputFile, SETTINGS.fontFamily);
  serialization::readPod(inputFile, SETTINGS.fontSize);
  serialization::readPod(inputFile, SETTINGS.lineSpacing);
  serialization::readPod(inputFile, SETTINGS.screenMargin);
  serialization::readPod(inputFile, SETTINGS.paragraphAlignment);
  serialization::readPod(inputFile, SETTINGS.extraParagraphSpacing);
  serialization::readPod(inputFile, SETTINGS.textAntiAliasing);
  serialization::readPod(inputFile, SETTINGS.hyphenationEnabled);
  serialization::readPod(inputFile, SETTINGS.embeddedStyle);
  serialization::readPod(inputFile, SETTINGS.bionicReadingMode);
  serialization::readPod(inputFile, SETTINGS.refreshMode);
  serialization::readPod(inputFile, SETTINGS.refreshFrequency);

  inputFile.close();
  return true;
}

bool saveForCachePath(const std::string& cachePath) {
  FsFile outputFile;
  if (!Storage.openFileForWrite("RPS", profilePathFor(cachePath), outputFile)) {
    return false;
  }

  serialization::writePod(outputFile, PROFILE_VERSION);
  serialization::writePod(outputFile, SETTINGS.readerPreset);
  serialization::writePod(outputFile, SETTINGS.fontFamily);
  serialization::writePod(outputFile, SETTINGS.fontSize);
  serialization::writePod(outputFile, SETTINGS.lineSpacing);
  serialization::writePod(outputFile, SETTINGS.screenMargin);
  serialization::writePod(outputFile, SETTINGS.paragraphAlignment);
  serialization::writePod(outputFile, SETTINGS.extraParagraphSpacing);
  serialization::writePod(outputFile, SETTINGS.textAntiAliasing);
  serialization::writePod(outputFile, SETTINGS.hyphenationEnabled);
  serialization::writePod(outputFile, SETTINGS.embeddedStyle);
  serialization::writePod(outputFile, SETTINGS.bionicReadingMode);
  serialization::writePod(outputFile, SETTINGS.refreshMode);
  serialization::writePod(outputFile, SETTINGS.refreshFrequency);

  outputFile.close();
  return true;
}
}  // namespace ReaderProfileStore
