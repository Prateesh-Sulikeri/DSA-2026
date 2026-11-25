---
tags: [dsa, index, index/pattern, pattern/arrays-hashing]
status: learning
last_revised: 2026-11-25
---

# 01 · Arrays: Index

← [[00-Master-Index|Master Index]]

## Sub-topics
| # | Sub-topic | Notes | Practice code | PDFs (local only, not in git) | Status |
|---|-----------|-------|---------------|-------------------------------|--------|
| 01 | Linear Scan | [[01-Linear-Scan]] | `01-Linear-Scan/code/` | [[Arrays_Linear_Scan_Cheat_Sheet.pdf\|Cheat Sheet]] · [[Arrays_Linear_Scan_Revision_Sheet.pdf\|Revision Sheet]] · [[Arrays_Linear_Scan_Detailed_Notes.pdf\|Detailed Notes]] | learning |
| 02 | Two Pointers | [[02-Two-Pointers]] | `02-Two-Pointers/code/` | – | learning |
| 03 | Hashing | [[03-Hashing]] | `03-Hashing/code/` | – | learning |
| 04 | Prefix Sum | [[04-Prefix-Sum]] | `04-Prefix-Sum/code/` | – | learning |

Run a practice file with `java <ProblemName>.java` from its `code/` folder (or F5 in Zed).

## Which technique?
| Signal in the problem | Jump to |
|-----------------------|---------|
| Element appearing > n/2 times, O(1) space | [[01-Linear-Scan#LC 169 · Majority Element · 🟢 Easy\|LC 169 Majority Element]] (Boyer-Moore) |
| Element appearing > n/2 times, O(n) space is fine | [[03-Hashing#LC 169 · Majority Element (HashMap) · 🟢 Easy\|LC 169 Majority Element (HashMap)]] (count map, return once a count passes `n / 2`) |
| Elements appearing > n/3 (or n/k) times | [[01-Linear-Scan#LC 229 · Majority Element II · 🟡 Medium\|LC 229 Majority Element II]] (Boyer-Moore, 2 candidates) |
| Max / min sum of contiguous subarray | [[01-Linear-Scan#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|LC 53 Maximum Subarray]] (Kadane) |
| Max product of contiguous subarray (negatives flip sign) | [[01-Linear-Scan#LC 152 · Maximum Product Subarray · 🟡 Medium\|LC 152 Maximum Product Subarray]] (Kadane, max + min) |
| Unsorted array, two indices with sum = target | [[03-Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy\|LC 1 Two Sum (HashMap)]] (value → index, O(n)) · [[02-Two-Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy\|sort + two pointers]] (O(n log n)) · [[01-Linear-Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy\|brute force]] (O(n²)) |
| Count / presence / duplicates | [[01-Linear-Scan#Template\|Linear Scan]] (HashMap) |
| Does any value appear twice? | [[03-Hashing#LC 217 · Contains Duplicate · 🟢 Easy\|LC 217 Contains Duplicate]] (HashSet, stop at the first failed `add`) |
| Same letters rearranged (is t an anagram of s?) | [[03-Hashing#LC 242 · Valid Anagram · 🟢 Easy\|LC 242 Valid Anagram]] (`int[26]`, `++` for s, `--` for t, all zero) |
| Group words that are anagrams of each other | [[03-Hashing#LC 49 · Group Anagrams · 🟡 Medium\|LC 49 Group Anagrams]] (HashMap sorted word → list, `computeIfAbsent`) |
| No repeats in any row / column / 3×3 box | [[03-Hashing#LC 36 · Valid Sudoku · 🟡 Medium\|LC 36 Valid Sudoku]] (27 seen-sets, box = `(r / 3) * 3 + c / 3`) |
| Longest run of consecutive values, unsorted, O(n) | [[03-Hashing#LC 128 · Longest Consecutive Sequence · 🟡 Medium\|LC 128 Longest Consecutive Sequence]] (HashSet, count only from `x` when `x − 1` is missing) |
| Top k most frequent values | [[03-Hashing#LC 347 · Top K Frequent Elements · 🟡 Medium\|LC 347 Top K Frequent Elements]] (count map → bucket by frequency, read from the top) |
| Sorted array, pair / triplet with sum = target | [[02-Two-Pointers#Template\|Two Pointers]] (opposite ends) |
| Remove / move / partition in place | [[02-Two-Pointers#Variants\|Two Pointers]] (slow / fast) |
| Sorted array, pair with sum = target (O(1) space) | [[02-Two-Pointers#LC 167 · Two Sum II · 🟡 Medium\|LC 167 Two Sum II]] (opposite ends) |
| Merge two sorted arrays in place | [[02-Two-Pointers#LC 88 · Merge Sorted Array · 🟢 Easy\|LC 88 Merge Sorted Array]] (fill from the back) |
| Sort 0 / 1 / 2 (three groups) in one pass | [[02-Two-Pointers#LC 75 · Sort Colors (Dutch National Flag) · 🟡 Medium\|LC 75 Sort Colors]] (Dutch flag, 3 pointers) |
| Move zeros to the end, keep the order | [[02-Two-Pointers#LC 283 · Move Zeroes · 🟢 Easy\|LC 283 Move Zeroes]] (slow / fast, swap non-zeros forward) |
| Count triplets that form a triangle | [[02-Two-Pointers#LC 611 · Valid Triangle Number · 🟡 Medium\|LC 611 Valid Triangle Number]] (sort, fix the largest, count `right − left`) |
| Max area between two lines | [[02-Two-Pointers#LC 11 · Container With Most Water · 🟡 Medium\|LC 11 Container With Most Water]] (opposite ends, move the shorter) |
| Triplets / quadruplets summing to target | [[02-Two-Pointers#LC 15 · 3Sum · 🟡 Medium\|LC 15 3Sum]] · [[02-Two-Pointers#LC 18 · 4Sum · 🟡 Medium\|LC 18 4Sum]] (sort + fix + two pointers) |
| Match two lists (each item used once), maximise the matches | [[02-Two-Pointers#LC 455 · Assign Cookies · 🟢 Easy\|LC 455 Assign Cookies]] (sort both, greedy match, drop what's too small) |
| Palindrome after deleting at most one character | [[02-Two-Pointers#LC 680 · Valid Palindrome II · 🟢 Easy\|LC 680 Valid Palindrome II]] (opposite ends, on a mismatch try skipping either side) |
| Sorted array, keep at most k copies of each value | [[02-Two-Pointers#LC 80 · Remove Duplicates from Sorted Array II · 🟡 Medium\|LC 80 Remove Duplicates II]] (slow / fast, compare with `write − 2`) |
| Fewest boats / pairs (at most 2, total ≤ limit) | [[02-Two-Pointers#LC 881 · Boats to Save People · 🟡 Medium\|LC 881 Boats to Save People]] (sort, pair the heaviest with the lightest) |
| Product of everything except `nums[i]`, no division | [[04-Prefix-Sum#LC 238 · Product of Array Except Self · 🟡 Medium\|LC 238 Product of Array Except Self]] (left products in the output, right product in one variable) |
| Many range-sum queries `[l, r]` | [[04-Prefix-Sum#Template\|Prefix Sum]] (`prefix[r + 1] − prefix[l]`) |
| Count subarrays with sum = k | [[04-Prefix-Sum#Variants\|Prefix Sum]] (prefix + HashMap of seen prefixes) |
| Rotate the array by k steps, in place | [[02-Two-Pointers#LC 189 · Rotate Array · 🟡 Medium\|LC 189 Rotate Array]] (`k %= n`, reverse all, reverse both parts) |
| Next lexicographic arrangement, in place | [[02-Two-Pointers#LC 31 · Next Permutation · 🟡 Medium\|LC 31 Next Permutation]] (pivot from the right, swap, reverse the suffix) |
| Water trapped between bars | [[02-Two-Pointers#LC 42 · Trapping Rain Water · 🔴 Hard\|LC 42 Trapping Rain Water]] (opposite ends, move the side with the smaller max) |

## Problems
| # | Problem | Sub-topic | Technique | Diff | Confidence | Practice file |
|---|---------|-----------|-----------|------|-----------|---------------|
| 1 | [[01-Linear-Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy\|Two Sum (Brute Force)]] | Linear Scan | Every pair, nested loops | 🟢 | ✅ | `TwoSumBruteForce.java` |
| 169 | [[01-Linear-Scan#LC 169 · Majority Element · 🟢 Easy\|Majority Element]] | Linear Scan | Boyer-Moore | 🟢 | ✅ | `MajorityElement.java` |
| 53 | [[01-Linear-Scan#LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium\|Maximum Subarray (Kadane)]] | Linear Scan | Kadane | 🟡 | ❌ | `MaximumSubarray.java` |
| 229 | [[01-Linear-Scan#LC 229 · Majority Element II · 🟡 Medium\|Majority Element II]] | Linear Scan | Boyer-Moore ×2 | 🟡 | ❌ | `MajorityElementII.java` |
| 152 | [[01-Linear-Scan#LC 152 · Maximum Product Subarray · 🟡 Medium\|Maximum Product Subarray]] | Linear Scan | Kadane max+min | 🟡 | ❌ | `MaximumProductSubarray.java` |
| 88 | [[02-Two-Pointers#LC 88 · Merge Sorted Array · 🟢 Easy\|Merge Sorted Array]] | Two Pointers | Two arrays, from the back | 🟢 | ✅ | `MergeSortedArray.java` |
| 283 | [[02-Two-Pointers#LC 283 · Move Zeroes · 🟢 Easy\|Move Zeroes]] | Two Pointers | Slow / fast, swap forward | 🟢 | ✅ | `MoveZeroes.java` |
| 167 | [[02-Two-Pointers#LC 167 · Two Sum II · 🟡 Medium\|Two Sum II]] | Two Pointers | Opposite ends, pair sum | 🟡 | ✅ | `TwoSumII.java` |
| 75 | [[02-Two-Pointers#LC 75 · Sort Colors (Dutch National Flag) · 🟡 Medium\|Sort Colors (Dutch Flag)]] | Two Pointers | Dutch flag (3 pointers) | 🟡 | ✅ | `SortColors.java` |
| 15 | [[02-Two-Pointers#LC 15 · 3Sum · 🟡 Medium\|3Sum]] | Two Pointers | Sort + fix 1 + pair | 🟡 | ✅ | `ThreeSum.java` |
| 611 | [[02-Two-Pointers#LC 611 · Valid Triangle Number · 🟡 Medium\|Valid Triangle Number]] | Two Pointers | Sort + fix largest + count | 🟡 | ✅ | `ValidTriangleNumber.java` |
| 18 | [[02-Two-Pointers#LC 18 · 4Sum · 🟡 Medium\|4Sum]] | Two Pointers | Sort + fix 2 + pair | 🟡 | ✅ | `FourSum.java` |
| 11 | [[02-Two-Pointers#LC 11 · Container With Most Water · 🟡 Medium\|Container With Most Water]] | Two Pointers | Opposite ends, move shorter | 🟡 | ✅ | `ContainerWithMostWater.java` |
| 80 | [[02-Two-Pointers#LC 80 · Remove Duplicates from Sorted Array II · 🟡 Medium\|Remove Duplicates from Sorted Array II]] | Two Pointers | Slow / fast, compare `write − 2` | 🟡 | ✅ | `RemoveDuplicatesFromSortedArrayII.java` |
| 680 | [[02-Two-Pointers#LC 680 · Valid Palindrome II · 🟢 Easy\|Valid Palindrome II]] | Two Pointers | Opposite ends, one skip | 🟢 | ✅ | `ValidPalindromeII.java` |
| 455 | [[02-Two-Pointers#LC 455 · Assign Cookies · 🟢 Easy\|Assign Cookies]] | Two Pointers | Sort both, greedy match | 🟢 | ✅ | `AssignCookies.java` |
| 1 | [[02-Two-Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy\|Two Sum (Sort + Two Pointers)]] | Two Pointers | Sort (value, index) pairs + opposite ends | 🟢 | ✅ | `TwoSumTwoPointers.java` |
| 881 | [[02-Two-Pointers#LC 881 · Boats to Save People · 🟡 Medium\|Boats to Save People]] | Two Pointers | Sort, heaviest + lightest | 🟡 | ✅ | `BoatsToSavePeople.java` |
| 31 | [[02-Two-Pointers#LC 31 · Next Permutation · 🟡 Medium\|Next Permutation]] | Two Pointers | Pivot, swap, reverse suffix | 🟡 | ❌ | `NextPermutation.java` |
| 189 | [[02-Two-Pointers#LC 189 · Rotate Array · 🟡 Medium\|Rotate Array]] | Two Pointers | Three reverses | 🟡 | ✅ | `RotateArray.java` |
| 42 | [[02-Two-Pointers#LC 42 · Trapping Rain Water · 🔴 Hard\|Trapping Rain Water]] | Two Pointers | Opposite ends, running max | 🔴 | ✅ | `TrappingRainWater.java` |
| 217 | [[03-Hashing#LC 217 · Contains Duplicate · 🟢 Easy\|Contains Duplicate]] | Hashing | HashSet seen-set | 🟢 | ✅ | `ContainsDuplicate.java` |
| 242 | [[03-Hashing#LC 242 · Valid Anagram · 🟢 Easy\|Valid Anagram]] | Hashing | Letter count `int[26]` | 🟢 | ✅ | `ValidAnagram.java` |
| 1 | [[03-Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy\|Two Sum (HashMap)]] | Hashing | HashMap complement | 🟢 | ✅ | `TwoSumHashMap.java` |
| 169 | [[03-Hashing#LC 169 · Majority Element (HashMap) · 🟢 Easy\|Majority Element (HashMap)]] | Hashing | Frequency map, early exit | 🟢 | ✅ | `MajorityElementHashMap.java` |
| 49 | [[03-Hashing#LC 49 · Group Anagrams · 🟡 Medium\|Group Anagrams]] | Hashing | Group by key (sorted word) | 🟡 | ✅ | `GroupAnagrams.java` |
| 347 | [[03-Hashing#LC 347 · Top K Frequent Elements · 🟡 Medium\|Top K Frequent Elements]] | Hashing | Count map + size-k min-heap / bucket by frequency | 🟡 | ✅ | `TopKFrequentElements.java` |
| 36 | [[03-Hashing#LC 36 · Valid Sudoku · 🟡 Medium\|Valid Sudoku]] | Hashing | Seen-set per row / column / box | 🟡 | ✅ | `ValidSudoku.java` |
| 128 | [[03-Hashing#LC 128 · Longest Consecutive Sequence · 🟡 Medium\|Longest Consecutive Sequence]] | Hashing | HashSet, count from run starts | 🟡 | ✅ | `LongestConsecutiveSequence.java` |
| 238 | [[04-Prefix-Sum#LC 238 · Product of Array Except Self · 🟡 Medium\|Product of Array Except Self]] | Prefix Sum | Prefix × suffix, two passes | 🟡 | ✅ | `ProductOfArrayExceptSelf.java` |

**Totals:** 30 problems · ✅ 26 · ⚠️ 0 · ❌ 4 (Linear Scan 5 · Two Pointers 16 · Hashing 8 · Prefix Sum 1). LC 1 Two Sum and LC 169 Majority Element are counted once per approach.
