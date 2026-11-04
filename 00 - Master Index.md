---
tags: [dsa, index, index/master]
last_revised: 2026-11-04
---

# DSA Master Index

Tracks progress **across all patterns**. Each pattern folder has its own `00 - Index` for the detail.

## Progress
| # | Pattern | Pattern index | Status | Problems | ✅ | ⚠️ | ❌ |
|---|---------|---------------|--------|----------|----|----|----|
| 01 | [[01 - Arrays & Hashing]] | [[01 - Arrays & Hashing/00 - Index\|index]] | learning | 4 | 0 | 1 | 3 |
| 02 | Two Pointers | – | not started | 0 | | | |
| 03 | Sliding Window | – | not started | 0 | | | |
| 04 | Prefix Sum | – | not started | 0 | | | |
| 05 | Binary Search | – | not started | 0 | | | |
| 06 | Stack / Monotonic Stack | – | not started | 0 | | | |
| 07 | Linked List | – | not started | 0 | | | |
| 08 | Fast & Slow Pointers | – | not started | 0 | | | |
| 09 | Binary Tree (DFS/BFS) | – | not started | 0 | | | |
| 10 | Binary Search Tree | – | not started | 0 | | | |
| 11 | Heap / Top-K | – | not started | 0 | | | |
| 12 | Intervals | – | not started | 0 | | | |
| 13 | Greedy | – | not started | 0 | | | |
| 14 | Trie | – | not started | 0 | | | |
| 15 | Bit Manipulation | – | not started | 0 | | | |
| 16 | Math & Geometry | – | not started | 0 | | | |
| 17 | Backtracking | – | not started | 0 | | | |
| 18 | Graphs (BFS/DFS) | – | not started | 0 | | | |
| 19 | Topological Sort | – | not started | 0 | | | |
| 20 | Union Find | – | not started | 0 | | | |
| 21 | Shortest Path | – | not started | 0 | | | |
| 22 | 1-D DP | – | not started | 0 | | | |
| 23 | 2-D DP | – | not started | 0 | | | |
| 24 | Advanced (Segment Tree, etc.) | – | not started | 0 | | | |
| | **Total** | | | **4** | **0** | **1** | **3** |

## Which pattern?
The first thing to check when you read a new problem.

| Signal in the problem | Pattern → technique |
|-----------------------|---------------------|
| Element appearing > n/2 times, O(1) space | [[01 - Arrays & Hashing]] → Boyer-Moore |
| Elements appearing > n/3 (or n/k) times | [[01 - Arrays & Hashing]] → Boyer-Moore, 2 candidates + verify |
| Max / min sum of contiguous subarray | [[01 - Arrays & Hashing]] → Kadane |
| Max product of contiguous subarray (negatives flip sign) | [[01 - Arrays & Hashing]] → Kadane, max + min |
| Count / presence / duplicates | [[01 - Arrays & Hashing]] → HashMap / HashSet |
| Count subarrays with sum = k | Prefix Sum + HashMap (04, not started) |
| Sorted array, search by order or range | Binary Search / Two Pointers (05 / 02, not started) |

## Redo queue
Problems marked ❌ or ⚠️, worst first. Clear a row when it reaches ✅.

| Confidence | # | Problem | Pattern |
|------------|---|---------|---------|
| ❌ | 53 | [[01 - Arrays & Hashing#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|Maximum Subarray (Kadane)]] | 01 |
| ❌ | 229 | [[01 - Arrays & Hashing#LC 229 · Majority Element II · 🟡 Medium\|Majority Element II]] | 01 |
| ❌ | 152 | [[01 - Arrays & Hashing#LC 152 · Maximum Product Subarray · 🟡 Medium\|Maximum Product Subarray]] | 01 |
| ⚠️ | 169 | [[01 - Arrays & Hashing#LC 169 · Majority Element · 🟢 Easy\|Majority Element]] | 01 |

## All problems
| # | Problem | Pattern | Technique | Diff | Confidence |
|---|---------|---------|-----------|------|-----------|
| 169 | [[01 - Arrays & Hashing#LC 169 · Majority Element · 🟢 Easy\|Majority Element]] | 01 Arrays & Hashing | Boyer-Moore | 🟢 | ⚠️ |
| 53 | [[01 - Arrays & Hashing#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|Maximum Subarray (Kadane)]] | 01 Arrays & Hashing | Kadane | 🟡 | ❌ |
| 229 | [[01 - Arrays & Hashing#LC 229 · Majority Element II · 🟡 Medium\|Majority Element II]] | 01 Arrays & Hashing | Boyer-Moore ×2 | 🟡 | ❌ |
| 152 | [[01 - Arrays & Hashing#LC 152 · Maximum Product Subarray · 🟡 Medium\|Maximum Product Subarray]] | 01 Arrays & Hashing | Kadane max+min | 🟡 | ❌ |
