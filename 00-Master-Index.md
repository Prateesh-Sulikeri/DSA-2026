---
tags: [dsa, index, index/master]
last_revised: 2026-11-25
---

# DSA Master Index

Tracks progress **across all patterns**. Each pattern folder has its own `00-Index` for the detail. A pattern can hold sub-topics (`↳` rows), each with its own notes file.

## Progress
| # | Pattern | Pattern index | Status | Problems | ✅ | ⚠️ | ❌ |
|---|---------|---------------|--------|----------|----|----|----|
| 01 | Arrays | [[01-Arrays/00-Index\|index]] | learning | 30 | 26 | 0 | 4 |
| ↳ 01.1 | [[01-Linear-Scan]] | | learning | 5 | 2 | 0 | 3 |
| ↳ 01.2 | [[02-Two-Pointers]] | | learning | 16 | 15 | 0 | 1 |
| ↳ 01.3 | [[03-Hashing]] | | learning | 8 | 8 | 0 | 0 |
| ↳ 01.4 | [[04-Prefix-Sum]] | | learning | 1 | 1 | 0 | 0 |
| 02 | Sliding Window | – | not started | 0 | | | |
| 03 | Binary Search | – | not started | 0 | | | |
| 04 | Stack / Monotonic Stack | – | not started | 0 | | | |
| 05 | Linked List | – | not started | 0 | | | |
| 06 | Fast & Slow Pointers | – | not started | 0 | | | |
| 07 | Binary Tree (DFS/BFS) | – | not started | 0 | | | |
| 08 | Binary Search Tree | – | not started | 0 | | | |
| 09 | Heap / Top-K | – | not started | 0 | | | |
| 10 | Intervals | – | not started | 0 | | | |
| 11 | Greedy | – | not started | 0 | | | |
| 12 | Trie | – | not started | 0 | | | |
| 13 | Bit Manipulation | – | not started | 0 | | | |
| 14 | Math & Geometry | – | not started | 0 | | | |
| 15 | Backtracking | – | not started | 0 | | | |
| 16 | Graphs (BFS/DFS) | – | not started | 0 | | | |
| 17 | Topological Sort | – | not started | 0 | | | |
| 18 | Union Find | – | not started | 0 | | | |
| 19 | Shortest Path | – | not started | 0 | | | |
| 20 | 1-D DP | – | not started | 0 | | | |
| 21 | 2-D DP | – | not started | 0 | | | |
| 22 | Advanced (Segment Tree, etc.) | – | not started | 0 | | | |
| | **Total** | | | **30** | **26** | **0** | **4** |

## Which pattern?
The first thing to check when you read a new problem.

| Signal in the problem | Pattern → technique |
|-----------------------|---------------------|
| Element appearing > n/2 times, O(1) space | [[01-Linear-Scan]] → Boyer-Moore |
| Element appearing > n/2 times, O(n) space is fine | [[03-Hashing]] → frequency map, early exit |
| Elements appearing > n/3 (or n/k) times | [[01-Linear-Scan]] → Boyer-Moore, 2 candidates + verify |
| Max / min sum of contiguous subarray | [[01-Linear-Scan]] → Kadane |
| Max product of contiguous subarray (negatives flip sign) | [[01-Linear-Scan]] → Kadane, max + min |
| Unsorted array, two indices with sum = target | [[03-Hashing]] → HashMap of value → index |
| Count / presence / duplicates | [[01-Linear-Scan]] → HashMap / HashSet |
| Does any value appear twice? | [[03-Hashing]] → HashSet seen-set |
| Same letters rearranged (anagram) | [[03-Hashing]] → letter count `int[26]` |
| Group items sharing a canonical form (anagrams) | [[03-Hashing]] → HashMap key → list |
| No repeats in any row / column / box (Sudoku) | [[03-Hashing]] → one seen-set per group |
| Longest run of consecutive values, unsorted, O(n) | [[03-Hashing]] → HashSet, count only from run starts (`x − 1` missing) |
| Top k most frequent values | [[03-Hashing]] → count map + bucket by frequency (or a size-k heap, Heap 09) |
| Count subarrays with sum = k | [[04-Prefix-Sum]] → prefix sum + HashMap of seen prefixes |
| Product / sum of everything except `nums[i]`, no division | [[04-Prefix-Sum]] → prefix × suffix, two passes |
| Sorted array, pair / triplet with sum = target | [[02-Two-Pointers]] → opposite ends |
| Remove / move / partition in place | [[02-Two-Pointers]] → slow / fast |
| Merge two sorted arrays in place | [[02-Two-Pointers]] → two arrays, fill from the back |
| Sort 0 / 1 / 2 (three groups) in one pass | [[02-Two-Pointers]] → Dutch flag, 3 pointers |
| Count triplets that form a triangle | [[02-Two-Pointers]] → sort, fix the largest side, count `right − left` |
| Max area between two lines | [[02-Two-Pointers]] → opposite ends, move the shorter line |
| Triplets / quadruplets summing to target | [[02-Two-Pointers]] → sort + fix k−2 + two pointers |
| Match two lists (each item once), maximise the matches | [[02-Two-Pointers]] → sort both + greedy match (also Greedy, 11) |
| Fewest boats / pairs (at most 2, total ≤ limit) | [[02-Two-Pointers]] → sort, heaviest + lightest (also Greedy, 11) |
| Water trapped between bars | [[02-Two-Pointers]] → opposite ends, running max (also Stack, 04) |
| Rotate the array by k steps, in place | [[02-Two-Pointers]] → three reverses (all, first k, last n − k) |
| Next lexicographic permutation, in place | [[02-Two-Pointers]] → pivot from the right, swap, reverse the suffix |
| Sorted array, search by order or range | Binary Search (03, not started) |

## Redo queue
Problems marked ❌ or ⚠️, worst first. Clear a row when it reaches ✅.

| Confidence | # | Problem | Pattern |
|------------|---|---------|---------|
| ❌ | 53 | [[01-Linear-Scan#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|Maximum Subarray (Kadane)]] | 01.1 |
| ❌ | 229 | [[01-Linear-Scan#LC 229 · Majority Element II · 🟡 Medium\|Majority Element II]] | 01.1 |
| ❌ | 152 | [[01-Linear-Scan#LC 152 · Maximum Product Subarray · 🟡 Medium\|Maximum Product Subarray]] | 01.1 |
| ❌ | 31 | [[02-Two-Pointers#LC 31 · Next Permutation · 🟡 Medium\|Next Permutation]] | 01.2 |

## All problems
| # | Problem | Pattern | Technique | Diff | Confidence |
|---|---------|---------|-----------|------|-----------|
| 1 | [[01-Linear-Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy\|Two Sum (Brute Force)]] | 01.1 Arrays › Linear Scan | Every pair, nested loops | 🟢 | ✅ |
| 169 | [[01-Linear-Scan#LC 169 · Majority Element · 🟢 Easy\|Majority Element]] | 01.1 Arrays › Linear Scan | Boyer-Moore | 🟢 | ✅ |
| 53 | [[01-Linear-Scan#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|Maximum Subarray (Kadane)]] | 01.1 Arrays › Linear Scan | Kadane | 🟡 | ❌ |
| 229 | [[01-Linear-Scan#LC 229 · Majority Element II · 🟡 Medium\|Majority Element II]] | 01.1 Arrays › Linear Scan | Boyer-Moore ×2 | 🟡 | ❌ |
| 152 | [[01-Linear-Scan#LC 152 · Maximum Product Subarray · 🟡 Medium\|Maximum Product Subarray]] | 01.1 Arrays › Linear Scan | Kadane max+min | 🟡 | ❌ |
| 88 | [[02-Two-Pointers#LC 88 · Merge Sorted Array · 🟢 Easy\|Merge Sorted Array]] | 01.2 Arrays › Two Pointers | Two arrays, from the back | 🟢 | ✅ |
| 283 | [[02-Two-Pointers#LC 283 · Move Zeroes · 🟢 Easy\|Move Zeroes]] | 01.2 Arrays › Two Pointers | Slow / fast, swap forward | 🟢 | ✅ |
| 167 | [[02-Two-Pointers#LC 167 · Two Sum II · 🟡 Medium\|Two Sum II]] | 01.2 Arrays › Two Pointers | Opposite ends, pair sum | 🟡 | ✅ |
| 75 | [[02-Two-Pointers#LC 75 · Sort Colors (Dutch National Flag) · 🟡 Medium\|Sort Colors (Dutch Flag)]] | 01.2 Arrays › Two Pointers | Dutch flag (3 pointers) | 🟡 | ✅ |
| 15 | [[02-Two-Pointers#LC 15 · 3Sum · 🟡 Medium\|3Sum]] | 01.2 Arrays › Two Pointers | Sort + fix 1 + pair | 🟡 | ✅ |
| 611 | [[02-Two-Pointers#LC 611 · Valid Triangle Number · 🟡 Medium\|Valid Triangle Number]] | 01.2 Arrays › Two Pointers | Sort + fix largest + count | 🟡 | ✅ |
| 18 | [[02-Two-Pointers#LC 18 · 4Sum · 🟡 Medium\|4Sum]] | 01.2 Arrays › Two Pointers | Sort + fix 2 + pair | 🟡 | ✅ |
| 11 | [[02-Two-Pointers#LC 11 · Container With Most Water · 🟡 Medium\|Container With Most Water]] | 01.2 Arrays › Two Pointers | Opposite ends, move shorter | 🟡 | ✅ |
| 80 | [[02-Two-Pointers#LC 80 · Remove Duplicates from Sorted Array II · 🟡 Medium\|Remove Duplicates from Sorted Array II]] | 01.2 Arrays › Two Pointers | Slow / fast, compare `write − 2` | 🟡 | ✅ |
| 680 | [[02-Two-Pointers#LC 680 · Valid Palindrome II · 🟢 Easy\|Valid Palindrome II]] | 01.2 Arrays › Two Pointers | Opposite ends, one skip | 🟢 | ✅ |
| 455 | [[02-Two-Pointers#LC 455 · Assign Cookies · 🟢 Easy\|Assign Cookies]] | 01.2 Arrays › Two Pointers | Sort both, greedy match | 🟢 | ✅ |
| 1 | [[02-Two-Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy\|Two Sum (Sort + Two Pointers)]] | 01.2 Arrays › Two Pointers | Sort (value, index) pairs + opposite ends | 🟢 | ✅ |
| 881 | [[02-Two-Pointers#LC 881 · Boats to Save People · 🟡 Medium\|Boats to Save People]] | 01.2 Arrays › Two Pointers | Sort, heaviest + lightest | 🟡 | ✅ |
| 31 | [[02-Two-Pointers#LC 31 · Next Permutation · 🟡 Medium\|Next Permutation]] | 01.2 Arrays › Two Pointers | Pivot, swap, reverse suffix | 🟡 | ❌ |
| 189 | [[02-Two-Pointers#LC 189 · Rotate Array · 🟡 Medium\|Rotate Array]] | 01.2 Arrays › Two Pointers | Three reverses | 🟡 | ✅ |
| 42 | [[02-Two-Pointers#LC 42 · Trapping Rain Water · 🔴 Hard\|Trapping Rain Water]] | 01.2 Arrays › Two Pointers | Opposite ends, running max | 🔴 | ✅ |
| 217 | [[03-Hashing#LC 217 · Contains Duplicate · 🟢 Easy\|Contains Duplicate]] | 01.3 Arrays › Hashing | HashSet seen-set | 🟢 | ✅ |
| 242 | [[03-Hashing#LC 242 · Valid Anagram · 🟢 Easy\|Valid Anagram]] | 01.3 Arrays › Hashing | Letter count `int[26]` | 🟢 | ✅ |
| 1 | [[03-Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy\|Two Sum (HashMap)]] | 01.3 Arrays › Hashing | HashMap complement | 🟢 | ✅ |
| 169 | [[03-Hashing#LC 169 · Majority Element (HashMap) · 🟢 Easy\|Majority Element (HashMap)]] | 01.3 Arrays › Hashing | Frequency map, early exit | 🟢 | ✅ |
| 49 | [[03-Hashing#LC 49 · Group Anagrams · 🟡 Medium\|Group Anagrams]] | 01.3 Arrays › Hashing | Group by key (sorted word) | 🟡 | ✅ |
| 347 | [[03-Hashing#LC 347 · Top K Frequent Elements · 🟡 Medium\|Top K Frequent Elements]] | 01.3 Arrays › Hashing | Count map + size-k min-heap / bucket by frequency | 🟡 | ✅ |
| 36 | [[03-Hashing#LC 36 · Valid Sudoku · 🟡 Medium\|Valid Sudoku]] | 01.3 Arrays › Hashing | Seen-set per row / column / box | 🟡 | ✅ |
| 128 | [[03-Hashing#LC 128 · Longest Consecutive Sequence · 🟡 Medium\|Longest Consecutive Sequence]] | 01.3 Arrays › Hashing | HashSet, count from run starts | 🟡 | ✅ |
| 238 | [[04-Prefix-Sum#LC 238 · Product of Array Except Self · 🟡 Medium\|Product of Array Except Self]] | 01.4 Arrays › Prefix Sum | Prefix × suffix, two passes | 🟡 | ✅ |
