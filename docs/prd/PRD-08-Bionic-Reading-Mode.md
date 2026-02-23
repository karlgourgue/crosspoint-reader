# PRD 08: Bionic Reading Mode

## Summary

Add a reader mode that bolds early parts of words to improve scan speed and reading focus, with Inkforge defaulting this mode to enabled.

## Problem

Some readers lose pace on dense text and want stronger visual anchors without changing font size or layout.

## Goals

- Provide an optional Bionic Reading mode for TXT and EPUB content.
- Keep rendering stable with existing alignment and pagination behavior.
- Make the feature discoverable and enabled by default in Inkforge.

## Non-Goals

- Perfect linguistic syllable splitting for every language.
- Rich per-language NLP processing on-device.

## User Stories

- As a reader, I want key word segments emphasized so I can scan faster.
- As a reader, I want this mode available in both TXT and EPUB reading.
- As a reader, I want to toggle this mode in settings if it does not fit my preference.

## Functional Requirements

1. Add a `Bionic Reading` reader toggle in settings.
2. Apply segment bolding for TXT line rendering.
3. Apply segment bolding during EPUB parsing/layout so pagination remains consistent with cached output.
4. Invalidate/rebuild EPUB section cache when Bionic Reading setting changes.
5. Set Inkforge first-boot default to enabled.

## Success Metrics

- Users can enable/disable the mode without crashes or stale pages.
- EPUB section cache correctly rebuilds after setting changes.
- Reader alignment remains correct for left/center/right paragraph modes.

## Risks

- ASCII-first tokenization may produce uneven results for multilingual books.
- Additional text segmentation can increase layout cost on long chapters.

## Rollout Plan

1. Ship v1 ASCII-focused segmentation for TXT and EPUB.
2. Collect feedback on readability and performance.
3. Expand segmentation quality for multilingual text in a follow-up phase.
