# PRD 04: Library Intelligence

## Summary

Add intelligent library organization: stronger "continue reading" ranking, tags/collections, and useful shelves such as Recently Added and In Progress.

## Problem

Large libraries become hard to navigate. Users need faster discovery and meaningful grouping without manual folder maintenance.

## Goals

- Surface the right next book quickly.
- Enable lightweight organization via tags and collections.
- Make high-value views first-class in the home experience.

## Non-Goals

- Building a cloud library backend.
- Full-text search indexing across all book content.

## User Stories

- As a reader, I want my active books to appear first.
- As a reader, I want to tag books and filter by tag.
- As a reader, I want shelves for recently added and unread books.

## Functional Requirements

1. Implement ranking score for continue reading based on:
   - Last-opened timestamp
   - Reading progress percent
   - Completion state
2. Add tags metadata for books (local storage).
3. Add collections that can include multiple tags or manual picks.
4. Add default shelves:
   - Continue Reading
   - In Progress
   - Unread
   - Recently Added
5. Add filtering UI by tag and shelf.

## Success Metrics

- 30% faster time-to-open next book in usability tests.
- 60% of active users interact with shelves weekly.
- Lower abandonment rate from home screen to reading.

## Risks

- Metadata schema migration complexity.
- Performance impact on low-memory operations.

## Rollout Plan

1. Ranking and Continue Reading refresh.
2. Tag model + storage.
3. Shelves and filter UX.
