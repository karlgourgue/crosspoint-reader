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
- Added selectable reader presets:
  - Compact
  - Classic
  - Airy
  - Large Print
  - Night Comfort
- Added per-book reader profile persistence for EPUB/TXT cache paths.
- Added refresh mode selector:
  - Full Each Page
  - Balanced
  - Aggressive Partial

### PRD-04 (Library Intelligence) - Phase 1

- Recent books capacity increased from 10 to 20.
- Home screen now prioritizes the last active book first to improve Continue Reading behavior.
- Added shelf filtering in library browser:
  - All
  - Continue Reading
  - In Progress
  - Unread
  - Recently Added

### PRD-05 (Battery/Performance) - Phase 1

- First-boot defaults tuned for balanced battery/performance:
  - Full refresh every 10 pages
  - Auto-sleep timeout: 15 minutes
  - Hide battery percentage in reader only
- Added user-selectable performance modes:
  - Battery Saver
  - Balanced
  - Performance

### PRD-07 (Controls) - Phase 1

- Control defaults are applied on first boot:
  - Side button layout: Prev/Next
  - Long-press chapter skip: enabled
  - Front mapping reset to safe default layout
- Added built-in control profiles:
  - Default
  - Left-handed
  - One-hand Commute
  - Minimal
- Added button test screen for live input verification.

### Branding

- Firmware flavor is exported via build flag `CROSSPOINT_FLAVOR`.
- `/api/status` now includes `flavor` in JSON.
- Boot log prints the flavor name and version.

## First-Boot Behavior

Inkforge defaults are only applied when `/.crosspoint/settings.bin` is missing or unreadable. Existing user settings are preserved.

## Next Phases

- PRD-08: Expand bionic algorithm beyond ASCII tokenization for multilingual text.
- PRD-04: Add tags, collections, and richer ranking signals.
- PRD-05: Add impact estimate copy in UI and deeper runtime telemetry.
- PRD-07: Add context-specific button profiles and gesture binding UI.
