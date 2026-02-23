# Inkforge Firmware

Inkforge is Karl's custom firmware flavor built on top of CrossPoint Reader for the Xteink X4.

## Intent

Inkforge tracks upstream CrossPoint while shipping opinionated defaults and iterative UX improvements from these PRDs:

- PRD-03 Reading UX Upgrades
- PRD-04 Library Intelligence
- PRD-05 Battery and Performance Modes
- PRD-07 Contextual Button Profiles
- PRD-08 Bionic Reading Mode

## What Is Implemented in v1

### PRD-03 (Reading UX) - Phase 1

- First-boot typography defaults are now tuned for readability:
  - Font family: Bookerly
  - Font size: Large
  - Line spacing: Wide
  - Margin: 10
  - Hyphenation: enabled
  - Bionic Reading: enabled by default

### PRD-04 (Library Intelligence) - Phase 1

- Recent books capacity increased from 10 to 20.
- Home screen now prioritizes the last active book first to improve Continue Reading behavior.

### PRD-05 (Battery/Performance) - Phase 1

- First-boot defaults tuned for balanced battery/performance:
  - Full refresh every 10 pages
  - Auto-sleep timeout: 15 minutes
  - Hide battery percentage in reader only

### PRD-07 (Controls) - Phase 1

- Control defaults are applied on first boot:
  - Side button layout: Prev/Next
  - Long-press chapter skip: enabled
  - Front mapping reset to safe default layout

### Branding

- Firmware flavor is exported via build flag `CROSSPOINT_FLAVOR`.
- `/api/status` now includes `flavor` in JSON.
- Boot log prints the flavor name and version.

## First-Boot Behavior

Inkforge defaults are only applied when `/.crosspoint/settings.bin` is missing or unreadable. Existing user settings are preserved.

## Next Phases

- PRD-03: Add explicit typography preset selector and per-book profile persistence.
- PRD-08: Expand bionic algorithm beyond ASCII tokenization for multilingual text.
- PRD-04: Add shelves, tags, and richer ranking signals.
- PRD-05: Add user-selectable mode switch (Battery Saver/Balanced/Performance).
- PRD-07: Add context-specific button profiles and gesture binding UI.
