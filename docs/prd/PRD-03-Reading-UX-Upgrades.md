# PRD 03: Reading UX Upgrades

## Summary

Improve reading comfort and control with typography presets, per-book display profiles, and faster-feeling page-turn behavior.

## Problem

Current reading settings are global and require repetitive manual adjustment. The page-turn experience is solid but can feel slow or visually noisy for some users and content types.

## Goals

- Add high-quality typography presets that users can switch quickly.
- Support per-book reading preferences.
- Reduce perceived page-turn latency and unnecessary full-screen refresh artifacts.

## Non-Goals

- Building a brand-new rendering engine.
- Full CSS-level EPUB typography customization.

## User Stories

- As a reader, I want one-tap typography profiles so I can optimize readability quickly.
- As a reader, I want each book to remember my preferred layout.
- As a reader, I want smoother page turns without extra flashing when possible.

## Functional Requirements

1. Add preset bundles (font, size, line-height, margins, paragraph spacing).
2. Provide at least five presets (e.g., Compact, Classic, Airy, Large Print, Night Comfort).
3. Persist per-book overrides keyed by stable document ID.
4. Implement page refresh modes:
   - Full refresh every page
   - Partial refresh with periodic full refresh
   - Aggressive partial refresh (user-tunable interval)
5. Add settings UI inside reader menu for quick switching.

## Success Metrics

- 80% of beta users keep a preset rather than using only manual tuning.
- 50% reduction in manual setting changes per reading session.
- Improved subjective page-turn satisfaction in user testing.

## Risks

- Partial refresh can increase ghosting.
- More settings can increase UI complexity.

## Rollout Plan

1. Typography presets and UI.
2. Per-book profile persistence.
3. Page refresh mode tuning and defaults.
