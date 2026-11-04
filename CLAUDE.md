# DSA Interview Prep Notes

This folder holds my DSA notes for interview prep. The same notes serve two purposes:
1. **Learning:** writing up each pattern and problem the first time.
2. **Revision:** skimming quickly before an interview.

Every rule below serves both goals. All the important information is in the note, but it can be skimmed in seconds.

## Structure: one file per pattern

- Each pattern gets **one file**, and the problems for that pattern go inside it as sections.
- File names: `NN - Pattern Name.md`. `NN` is the study order (for example `03 - Sliding Window.md`).
- `00 - Index.md` is the hub. It links every pattern and has a "Which pattern?" lookup table.
- If one problem's write-up gets too long for its pattern file (more than about 60 lines), move it to `Problems/<Problem Name>.md` and link it from the pattern file with a short entry.
- A problem that fits several patterns goes under its **main** pattern. The others get a single-line link to it under **Related**.

### Suggested pattern order

```
01 Arrays & Hashing        09 Binary Tree (DFS/BFS)   17 Backtracking
02 Two Pointers            10 Binary Search Tree      18 Graphs (BFS/DFS)
03 Sliding Window          11 Heap / Top-K            19 Topological Sort
04 Prefix Sum              12 Intervals               20 Union Find
05 Binary Search           13 Greedy                  21 Shortest Path
06 Stack / Monotonic Stack 14 Trie                    22 1-D DP
07 Linked List             15 Bit Manipulation        23 2-D DP
08 Fast & Slow Pointers    16 Math & Geometry         24 Advanced (Segment Tree, etc.)
```

Rename, merge or reorder these as the notes grow. Keep the numbering continuous.

## Pattern file template

Every pattern file uses these sections **in this order**. Leave out a section only if it truly doesn't apply.

````markdown
---
tags: [dsa, pattern/sliding-window]
status: learning   # learning | revising | confident
last_revised: 2026-11-04
---

# Sliding Window

## TL;DR
- **What:** one line on the core idea.
- **When:** the main signal that tells you to use it.
- **Complexity:** typical time / space.

**Rule:** the whole pattern in one sentence.

## Recognition Signals
- "Longest / shortest / count subarray or substring that ..." → this pattern
- Input is contiguous (array or string) and the constraint can be checked as the window grows or shrinks
- ✗ Not this when: negative numbers break monotonicity → use Prefix Sum + HashMap instead

## Template
```java
// Generic skeleton, with a short comment on each important line
```

## Variants
- **Fixed-size window:** how it differs from the template.
- **Variable-size window:** how it differs from the template.

## Problems
(Ordered from easy to hard. Each uses the problem block below.)

## Pitfalls
- Off-by-one when calculating the window length: `r - l + 1`
- Forgetting to remove from the map when the count drops to 0

## Related
- [[02 - Two Pointers]]: how it relates
````

## Problem block template

Each problem inside the `## Problems` section looks like this:

````markdown
### LC 3 · Longest Substring Without Repeating Characters · 🟡 Medium
[Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) · Confidence: ⚠️

- **Key insight:** the single idea that cracks the problem (one line).
- **Approach:**
  1. Step
  2. Step
  3. Step
- **Brute → Optimal:** O(n³) check every substring → O(n) window + set.
- **Complexity:** O(n) time · O(min(n, charset)) space
- **Edge cases:** empty string, all the same character, all unique.

> [!example]- Code (Java)
> ```java
> // solution
> ```
````

Field rules:
- **Difficulty:** 🟢 Easy · 🟡 Medium · 🔴 Hard
- **Confidence:** ✅ can solve cold · ⚠️ shaky, needs revisiting · ❌ couldn't solve, must redo. Update it on every revision pass.
- **Key insight** is required. It's the line I'll actually read during revision.
- Code always goes inside a **collapsed callout** (`> [!example]-`). That way a revision skim shows only the ideas, and the code is one click away.
- **Brute → Optimal** is optional. Include it when the jump between the two is itself worth remembering.

## Writing style

- Bullets, not paragraphs. If a bullet needs more than 2 lines, split it up.
- End each concept with a bold **Rule:** one-liner, matching the style of the `🍵 Java` notes.
- Code: **Java**. Comment only the lines that aren't obvious. Use clear variable names (`left`/`right`, not `i`/`j`, when they mean window bounds).
- Use `→` for "leads to / becomes", and `✗` for "not this when".
- Prefer tables for comparisons (for example, variants side by side or BFS vs DFS).
- Use Obsidian `[[wikilinks]]` for links between notes and between patterns.
- Don't add filler or textbook history. If it won't help me in an interview, leave it out.

## Revision layers

The notes have three reading depths. They line up with the `handwritten-notes-pdf` skill:

| Layer | What to read | PDF |
|-------|--------------|-----|
| 5-min skim | **TL;DR** + **Rule** of every pattern | Cheat Sheet |
| 30-min revision | + Recognition Signals, Template, each problem's **Key insight** | Revision Sheet |
| Full study | Everything, including code | Detailed Notes |

So the TL;DR, Rule and Key insight lines must make sense **on their own**, without the rest of the note.

## Instructions for Claude

When I ask you to add a problem or a pattern:
1. Work out the problem's main pattern and add it to that pattern file. Create the file from the template if it doesn't exist yet, and add it to `00 - Index.md`.
2. Insert the problem in difficulty order (easy → hard) and follow the problem block template exactly.
3. If the problem introduces a new variant or pitfall, also update **Variants**, **Pitfalls** or **Recognition Signals** in that pattern file.
4. Set `last_revised` in the frontmatter to today's date whenever the file meaningfully changes.
5. Don't rewrite my own wording in notes I've already written unless I ask. Point out mistakes instead of silently "fixing" them.
6. When explaining a solution, give the key insight first and then the steps. Keep it short.
