---
tags: [dsa, pattern/arrays-hashing, pattern/arrays-hashing/two-pointers]
status: learning
last_revised: 2026-11-24
---

# Two Pointers

## TL;DR
- **What:** two indices move through the array, and each step discards elements that can't be part of the answer.
- **When:** the array is sorted (or can be sorted), and you compare a pair or rearrange the array in place.
- **Complexity:** O(n) time after sorting (O(n log n) if you sort first) · O(1) extra space.

**Rule:** if the order tells you which pointer to move, one pass with two pointers replaces the nested loop.

## Recognition Signals
- "Sorted array, find a pair / triplet with sum = target" → opposite ends
- "Remove duplicates / move zeros / partition in place" → slow (write) + fast (read) pointers
- "Sorted array, keep at most k copies of each value" → slow / fast, compare with `write − k`
- "Sort an array of only 0 / 1 / 2 (three groups) in one pass" → three pointers, Dutch National Flag
- "k numbers that sum to target" → sort, fix k − 2 numbers with loops, two pointers for the last pair
- "Is it a palindrome?", "reverse in place" → opposite ends, moving inward
- "Palindrome if you delete at most one character" → opposite ends; at the first mismatch, try skipping either side
- "Container / max area between two lines" → opposite ends, move the shorter side
- "Count triplets that form a triangle" / "count pairs with sum > x" → sort, fix the largest, add `right − left` in one go
- "Merge two sorted arrays" → one pointer per array
- "Match items from two lists, each used once, maximise the matches" (size ≥ need) → sort both, one pointer per list, greedy
- "Fewest boats / pairs, at most 2 per group, total ≤ limit" → sort, pair the heaviest with the lightest (opposite ends)
- "Water trapped between bars" → opposite ends with a running max on each side; move the side with the smaller max
- "Rotate the array right by k steps, in place" → reverse all, then reverse the first k and the last n − k
- "Next lexicographic arrangement, in place" → scan from the right for the first dip (pivot), swap, reverse the suffix
- "Merge in place, with the free space at the end" → pointers start at the ends and fill from the back
- ✗ Not this when: the array is unsorted and you need original indices → HashMap ([[01-Linear-Scan]])
- ✗ Not this when: "longest / shortest subarray that satisfies ..." → [[02-Sliding-Window]] (both pointers move the same way, tracking a window)

## Template
```java
// Opposite ends: sorted array, find a pair with sum = target
int left = 0, right = nums.length - 1;
while (left < right) {                    // < not <=: a pair needs two different elements
    int sum = nums[left] + nums[right];
    if (sum == target) return new int[]{left, right};
    else if (sum < target) left++;        // need a bigger sum → move the small side up
    else right--;                         // need a smaller sum → move the big side down
}
return new int[]{-1, -1};

// Slow / fast: rewrite the array in place, keeping only valid elements
int write = 0;                            // next slot for a kept element
for (int read = 0; read < nums.length; read++) {
    if (keep(nums[read])) nums[write++] = nums[read];
}
return write;                             // new length
```

## Variants
| Variant | Pointers start | Move rule | Typical problems |
|---------|----------------|-----------|------------------|
| **Slow / fast, keep up to k copies** | both at `0` | keep `nums[read]` if `write < k` or it differs from `nums[write − k]` | Remove Duplicates II (k = 2) |
| **Opposite ends** | `0` and `n − 1` | move the side that can't improve the answer | pair sum, palindrome, container |
| **Opposite ends, one skip allowed** | `0` and `n − 1` | at the first mismatch, check both `[left + 1, right]` and `[left, right − 1]` | Valid Palindrome II |
| **Slow / fast (same direction)** | both at `0` | `read` every step, `write` only when keeping | remove duplicates, move zeros |
| **Two arrays** | `0` in each | advance the smaller element | merge sorted, intersection |
| **Two arrays, greedy matching** | `0` in each (both sorted) | match → advance both; too small → advance only the supply pointer | Assign Cookies |
| **Opposite ends, greedy pairing** | `0` and `n − 1` (sorted) | the heavy side always leaves; the light side leaves only if the pair fits | Boats to Save People |
| **Opposite ends, running max per side** | `0` and `n − 1` | move the side with the smaller max; add `max − height` there | Trapping Rain Water |
| **From the right: pivot, swap, reverse** | scan leftward from `n − 2` | find the first `nums[i] < nums[i + 1]`, swap with the rightmost bigger value, reverse the suffix | Next Permutation |
| **Reverse in parts (rotation)** | `0` and `n − 1`, then each part | three opposite-ends reverses: all, `[0, k − 1]`, `[k, n − 1]` | Rotate Array |
| **Two arrays, from the back** | last index of each | write the larger element into the end slot | in-place merge (Merge Sorted Array) |
| **Three pointers (partition)** | `low = mid = 0`, `high = n − 1` | `mid` reads; swap into the `low` / `high` zones | Sort Colors (Dutch flag) |
| **Fix one + opposite ends** | outer `i`, inner `i+1` and `n − 1` | outer loop, then pair-sum inside | 3Sum, 4Sum (fix two) |
| **Fix the largest + count** | outer `k` from the end, inner `0` and `k − 1` | match → count `right − left`, `right--`; else `left++` | Valid Triangle Number |

## Problems

### LC 88 · Merge Sorted Array · 🟢 Easy
[Link](https://leetcode.com/problems/merge-sorted-array/) · Confidence: ✅

- **Key insight:** fill `nums1` from the **back**. The empty slots are at the end, so writing the largest values there never overwrites a value you still need.
- **Approach:**
  1. `i = m − 1` (end of real `nums1`), `j = n − 1` (end of `nums2`), `k = m + n − 1` (write slot).
  2. While `j >= 0`: write the larger of `nums1[i]` and `nums2[j]` to `nums1[k]`, then move that pointer and `k` back.
  3. Stop when `nums2` is used up. Whatever is left of `nums1` is already in place.
- **Brute → Optimal:** copy `nums2` into the end and sort, O((m+n) log(m+n)) → merge from the front into an extra array, O(m+n) space → merge from the back, O(1) space.
- **Complexity:** O(m + n) time · O(1) space
- **Edge cases:** `nums2` empty (`n = 0`), `nums1` empty (`m = 0`), all of `nums2` smaller than all of `nums1`, duplicates.
- **Clarifying questions:** does `nums1` always have exactly `n` free slots at the end? Must it be in place? Are both arrays sorted ascending?
- **Follow-ups:** merge k sorted arrays → min-heap, O(N log k) · return a new array instead → merge from the front · no free space in either array → gap method (shell-sort style).
- **Practice:** `01-Arrays/02-Two-Pointers/code/MergeSortedArray.java` · run: `java MergeSortedArray.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public void merge(int[] nums1, int m, int[] nums2, int n) {
>         int i = m - 1, j = n - 1, k = m + n - 1;
>         while (j >= 0) {                              // loop on nums2 only: leftover nums1 is already in place
>             if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];  // i >= 0 guard: nums1 may run out first
>             else nums1[k--] = nums2[j--];
>         }
>     }
> }
> ```

### LC 283 · Move Zeroes · 🟢 Easy
[Link](https://leetcode.com/problems/move-zeroes/) · Confidence: ✅

- **Key insight:** slow / fast pointers. `read` scans every element and `write` marks the next slot for a non-zero. Swapping each non-zero into `write` keeps the non-zeros in order and pushes the zeros to the end.
- **Approach:**
  1. `write = 0`.
  2. For each `read`: if `nums[read] != 0`, swap `nums[read]` and `nums[write]`, then `write++`.
  3. Everything from `write` onward is now zero.
- **Brute → Optimal:** copy the non-zeros into a new array and pad with zeros, O(n) space → two pointers in place, O(1) space.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single element, all zeros, no zeros, zeros already at the end, zeros at the start, negatives.
- **Clarifying questions:** must it be in place? Must the non-zeros keep their relative order? Should I minimise the number of writes?
- **Follow-ups:** fewer writes → copy the non-zeros forward, then fill the tail with zeros (or swap only when `read != write`) · remove a value instead (LC 27) → same loop, return `write` · move zeros to the front → scan from the back.
- **Practice:** `01-Arrays/02-Two-Pointers/code/MoveZeroes.java` · run: `java MoveZeroes.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public void moveZeroes(int[] nums) {
>         int write = 0;                                 // next slot for a non-zero
>         for (int read = 0; read < nums.length; read++) {
>             if (nums[read] != 0) {
>                 int temp = nums[write];                // swap, so the zero moves back to read
>                 nums[write] = nums[read];
>                 nums[read] = temp;
>                 write++;
>             }
>         }
>     }
> }
> ```

### LC 680 · Valid Palindrome II · 🟢 Easy
[Link](https://leetcode.com/problems/valid-palindrome-ii/) · Confidence: ✅

- **Key insight:** walk in from both ends. At the first mismatch, one of the two mismatched characters must be deleted, so the answer is whether `s[left + 1 .. right]` **or** `s[left .. right − 1]` is a palindrome. Check both, since you can't tell which one to drop.
- **Approach:**
  1. `left = 0`, `right = n − 1`. While `left < right` and the characters match, move both inward.
  2. On the first mismatch, return `isPalindrome(left + 1, right) || isPalindrome(left, right − 1)`.
  3. If the loop finishes with no mismatch, it's already a palindrome → `true`.
- **Brute → Optimal:** delete each character in turn and check for a palindrome, O(n²) → one pass, plus at most two checks on the remaining middle, O(n).
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single character, two different characters (`"ab"` → true), already a palindrome, the right character must go (`"cbbcc"`), the left one must go (`"ccbbc"`), two deletions needed (`"abcda"` → false).
- **Clarifying questions:** lowercase letters only, or mixed case and symbols? Is it at most one deletion, or exactly one? Can the string be empty?
- **Follow-ups:** at most k deletions (LC 1216) → DP: `n − longest palindromic subsequence ≤ k`, O(n²) · ignore case and non-alphanumerics (LC 125) → skip them with inner while loops · return which index to delete → the `left` or `right` that passed the check.
- **Practice:** `01-Arrays/02-Two-Pointers/code/ValidPalindromeII.java` · run: `java ValidPalindromeII.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public boolean validPalindrome(String s) {
>         int left = 0, right = s.length() - 1;
>         while (left < right) {
>             if (s.charAt(left) != s.charAt(right))     // one deletion allowed: try dropping either side
>                 return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
>             left++;
>             right--;
>         }
>         return true;
>     }
>
>     private boolean isPalindrome(String s, int left, int right) {
>         while (left < right) {
>             if (s.charAt(left++) != s.charAt(right--)) return false;
>         }
>         return true;
>     }
> }
> ```

### LC 455 · Assign Cookies · 🟢 Easy
[Link](https://leetcode.com/problems/assign-cookies/) · Confidence: ✅

- **Key insight:** sort both arrays and give each cookie to the least greedy child still waiting. If a cookie is too small for that child, it's too small for every child after them, so throw the **cookie** away, not the child.
- **Approach:**
  1. Sort `g` (greed) and `s` (cookie sizes). `child = 0`, `cookie = 0`.
  2. While both are in range: if `s[cookie] >= g[child]`, the child is content → `child++`.
  3. Always `cookie++` (it's either eaten or useless). Return `child`, the number of content children.
- **Brute → Optimal:** for each child, scan every unused cookie for the smallest one that fits, O(n · m) → sort both + two pointers, O(n log n + m log m).
- **Complexity:** O(n log n + m log m) time (the sorting) · O(1) extra space, apart from the sort itself
- **Edge cases:** no cookies, all cookies too small, more cookies than children, unsorted input, duplicates where the smallest cookie fits nobody (`g=[2,2,2]`, `s=[1,2,2]` → 2).
- **Clarifying questions:** can a child get more than one cookie? Can a cookie be split? Are the arrays already sorted, and may I sort them in place?
- **Follow-ups:** why is greedy safe → giving the least greedy child a bigger cookie than needed never helps anyone later (swap argument) · may not change the input → sort copies · values in a small range → counting sort, O(n + m + range).
- **Practice:** `01-Arrays/02-Two-Pointers/code/AssignCookies.java` · run: `java AssignCookies.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int findContentChildren(int[] g, int[] s) {
>         Arrays.sort(g);
>         Arrays.sort(s);
>         int child = 0, cookie = 0;
>         while (child < g.length && cookie < s.length) {
>             if (s[cookie] >= g[child]) child++;        // fits → this child is content
>             cookie++;                                  // used up, or too small for everyone left
>         }
>         return child;                                  // number of content children
>     }
> }
> ```

### LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy
[Link](https://leetcode.com/problems/two-sum/) · Confidence: ✅

- **Key insight:** two pointers need sorted values, but sorting shuffles the indices that LC 1 asks for. So sort `{value, original index}` pairs, run opposite-ends two pointers on the values, and return the stored indices.
- **Approach:**
  1. Build `pairs[i] = {nums[i], i}`.
  2. Sort `pairs` by value. Each index travels with its value.
  3. `left = 0`, `right = n − 1`. Sum too small → `left++`, too big → `right--`.
  4. Sum equals `target` → return `{pairs[left][1], pairs[right][1]}`.
- **Brute → Optimal:** O(n²) [[01-Linear-Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy|every pair]] → O(n log n) this one → O(n) [[03-Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy|HashMap]]. On unsorted input the HashMap wins; this approach only wins when the input is already sorted ([[#LC 167 · Two Sum II · 🟡 Medium|LC 167]], O(1) space).
- **Complexity:** O(n log n) time · O(n) space (the pairs array)
- **Edge cases:** the same value twice (`[3,3]`, target 6, both copies stay as separate pairs), negatives, the answer's indices come back in either order, the pair at the very ends.
- **Clarifying questions:** is the array already sorted? Can I return the two indices in any order? Is there always exactly one answer?
- **Follow-ups:** the array is already sorted (LC 167) → skip the pairs, O(1) space · return all unique pairs → after a match, skip equal values on both sides · three numbers (LC 15) → fix one, then run this on the rest.
- **Practice:** `01-Arrays/02-Two-Pointers/code/TwoSumTwoPointers.java` · run: `java TwoSumTwoPointers.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int[] twoSum(int[] nums, int target) {
>         int n = nums.length;
>         int[][] pairs = new int[n][];                     // {value, original index}
>         for (int i = 0; i < n; i++) pairs[i] = new int[]{nums[i], i};
>         Arrays.sort(pairs, (a, b) -> Integer.compare(a[0], b[0]));   // sort by value, the index travels along
>
>         int left = 0, right = n - 1;
>         while (left < right) {
>             int sum = pairs[left][0] + pairs[right][0];
>             if (sum == target) return new int[]{pairs[left][1], pairs[right][1]};
>             if (sum < target) left++;                     // need a bigger sum
>             else right--;                                 // need a smaller sum
>         }
>         return new int[]{-1, -1};
>     }
> }
> ```

### LC 167 · Two Sum II · 🟡 Medium
[Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) · Confidence: ✅

- **Key insight:** the array is sorted, so the sum tells you which pointer to move: too small → `left++`, too big → `right--`. No HashMap needed, O(1) space.
- **Approach:**
  1. `left = 0`, `right = n − 1`. Loop while `left < right`.
  2. `sum == target` → return `{left + 1, right + 1}` (the answer is **1-indexed**).
  3. `sum < target` → `left++`; `sum > target` → `right--`.
- **Brute → Optimal:** O(n²) every pair → O(n log n) binary search for each partner → O(n) two pointers, O(1) space (the HashMap from [[03-Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy|LC 1]] works but wastes O(n) space).
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** only two elements, negatives, duplicates that form the answer (`[1,3,3,8]`, target 6), the pair at the far end.
- **Clarifying questions:** is exactly one answer guaranteed? 1-indexed or 0-indexed output? Must it be O(1) extra space? Can I use the same element twice?
- **Follow-ups:** return all unique pairs → on a match move both pointers and skip duplicates (the 3Sum inner loop) · count pairs with sum < target → when `sum < target`, add `right − left` and `left++` · unsorted input → HashMap (LC 1).
- **Practice:** `01-Arrays/02-Two-Pointers/code/TwoSumII.java` · run: `java TwoSumII.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int[] twoSum(int[] numbers, int target) {
>         int left = 0, right = numbers.length - 1;
>         while (left < right) {                         // < not <=: can't use one element twice
>             int sum = numbers[left] + numbers[right];
>             if (sum == target) return new int[]{left + 1, right + 1};  // 1-indexed answer
>             if (sum < target) left++;                  // need bigger → move the small side up
>             else right--;                              // need smaller → move the big side down
>         }
>         return new int[]{-1, -1};
>     }
> }
> ```

### LC 75 · Sort Colors (Dutch National Flag) · 🟡 Medium
[Link](https://leetcode.com/problems/sort-colors/) · Confidence: ✅

- **Key insight:** three pointers split the array into `0s | 1s | unknown | 2s`. Each step shrinks the unknown part by one.
- **Approach:**
  1. `low = 0`, `mid = 0`, `high = n − 1`. Loop while `mid <= high`.
  2. `nums[mid] == 0` → swap with `low`, then `low++` and `mid++`.
  3. `nums[mid] == 1` → `mid++`.
  4. `nums[mid] == 2` → swap with `high`, then `high--` only. **Don't move `mid`**: the value swapped in hasn't been checked yet.
- **Brute → Optimal:** `Arrays.sort` O(n log n) → count the 0/1/2s and rewrite (two passes) → one pass with three pointers.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single element, all the same, no 1s, a 2 swapped in from the end that is also a 2 (`[2,1,2]`).
- **Clarifying questions:** only the values 0, 1 and 2? In place, without the library sort? Is one pass required?
- **Follow-ups:** k colours (Sort Colors II, LintCode 143) → counting sort, or recursive partitioning, O(n log k) · stable order needed → counting pass + rewrite · same idea is quicksort's 3-way partition.
- **Practice:** `01-Arrays/02-Two-Pointers/code/SortColors.java` · run: `java SortColors.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public void sortColors(int[] nums) {
>         int low = 0, mid = 0, high = nums.length - 1;
>         while (mid <= high) {                      // <=: the element at high is still unknown
>             if (nums[mid] == 0) swap(nums, low++, mid++);
>             else if (nums[mid] == 2) swap(nums, mid, high--); // mid stays: the new nums[mid] is unchecked
>             else mid++;
>         }
>     }
>
>     private void swap(int[] nums, int a, int b) {
>         int temp = nums[a]; nums[a] = nums[b]; nums[b] = temp;
>     }
> }
> ```

### LC 15 · 3Sum · 🟡 Medium
[Link](https://leetcode.com/problems/3sum/) · Confidence: ✅

- **Key insight:** sort, fix the first number, then the other two are a sorted pair-sum → opposite-ends two pointers.
- **Approach:**
  1. **Sort** the array.
  2. For each `i`: skip it if `nums[i] == nums[i − 1]`.
  3. `j = i + 1`, `k = n − 1`. Sum too small → `j++`, too big → `k--`.
  4. On a match: add it, move **both** inward (`j++`, `k--`), then skip duplicates of `j` and `k`.
- **Brute → Optimal:** O(n³) every triple + a set for duplicates → O(n²) sort + two pointers, with no set needed.
- **Complexity:** O(n²) time · O(1) extra space (not counting the output and the sort)
- **Edge cases:** no triplet, all zeros, many repeated values (`[-2,-2,0,0,2,2]`), all positive.
- **Clarifying questions:** return values or indices? Must the triplets be unique? Does the output order matter? Can I sort the input?
- **Follow-ups:** any target instead of 0 → same code, compare with `target` · 3Sum Closest (LC 16) → track the smallest `|sum − target|` · k-Sum → recursion down to the 2-pointer pair (LC 18).
- **Practice:** `01-Arrays/02-Two-Pointers/code/ThreeSum.java` · run: `java ThreeSum.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public List<List<Integer>> threeSum(int[] nums) {
>         Arrays.sort(nums);                                   // two pointers need sorted input
>         List<List<Integer>> res = new ArrayList<>();
>         for (int i = 0; i < nums.length - 2; i++) {
>             if (i > 0 && nums[i] == nums[i - 1]) continue;   // same first number → same triplets
>             int j = i + 1, k = nums.length - 1;
>             while (j < k) {
>                 int sum = nums[i] + nums[j] + nums[k];
>                 if (sum == 0) {
>                     res.add(Arrays.asList(nums[i], nums[j], nums[k]));
>                     j++;
>                     k--;                                     // both move INWARD
>                     while (j < k && nums[j] == nums[j - 1]) j++;
>                     while (j < k && nums[k] == nums[k + 1]) k--;
>                 }
>                 else if (sum > 0) k--;
>                 else j++;
>             }
>         }
>         return res;
>     }
> }
> ```

### LC 611 · Valid Triangle Number · 🟡 Medium
[Link](https://leetcode.com/problems/valid-triangle-number/) · Confidence: ✅

- **Key insight:** sort, then fix the **largest** side `k`. If `nums[left] + nums[right] > nums[k]`, every index from `left` to `right − 1` also works with `right`, so add `right − left` at once.
- **Approach:**
  1. Sort. For `k` from `n − 1` down to `2`: `left = 0`, `right = k − 1`.
  2. `nums[left] + nums[right] > nums[k]` → `count += right − left`, then `right--`.
  3. Otherwise the sum is too small → `left++`.
- **Brute → Optimal:** O(n³) check every triple → O(n² log n) sort + binary search for the third side → O(n²) sort + fix the largest + two pointers.
- **Complexity:** O(n²) time · O(1) extra space (not counting the sort)
- **Edge cases:** fewer than 3 elements, zeros (a 0 side never forms a triangle), all the same, `a + b == c` (not a triangle, the check is strictly `>`).
- **Clarifying questions:** can values be 0? Count triplets by index (duplicates count separately) or unique value sets? Can I sort the input?
- **Follow-ups:** list the triangles instead → on a match, output every `(nums[x], nums[right], nums[k])` for `x` in `[left, right)` · why fix the largest side → once sorted, `a + b > c` is the only check that can fail, so the other two are free.
- **Practice:** `01-Arrays/02-Two-Pointers/code/ValidTriangleNumber.java` · run: `java ValidTriangleNumber.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int triangleNumber(int[] nums) {
>         Arrays.sort(nums);
>         int count = 0;
>         for (int k = nums.length - 1; k >= 2; k--) {      // k = largest side
>             int left = 0, right = k - 1;
>             while (left < right) {
>                 if (nums[left] + nums[right] > nums[k]) {
>                     count += right - left;                 // every left..right-1 also works with right
>                     right--;
>                 }
>                 else left++;                               // too small → need a bigger short side
>             }
>         }
>         return count;
>     }
> }
> ```

### LC 18 · 4Sum · 🟡 Medium
[Link](https://leetcode.com/problems/4sum/) · Confidence: ✅

- **Key insight:** it's 3Sum with one more fixed pointer. Two nested loops fix `i` and `j`, then a pair-sum with two pointers finds the rest.
- **Approach:**
  1. Sort. Outer loop `i`, skipping duplicates (`i > 0`).
  2. Inner loop `j` from `i + 1`, skipping duplicates (`j > i + 1`, not `j > 0`).
  3. `left = j + 1`, `right = n − 1`, the same as 3Sum, compared against `target`.
  4. Add up the sum as a **`long`**: four values near 10⁹ overflow an `int`.
- **Complexity:** O(n³) time · O(1) extra space (not counting the output and the sort)
- **Edge cases:** fewer than 4 elements, all the same, int overflow (`[10⁹ ×4]`, target −294967296 → `[]`), negative target.
- **Clarifying questions:** unique quadruplets only? How big are the values (overflow risk)? Can the target be negative?
- **Follow-ups:** general k-Sum → recursive `kSum(start, k, target)` with 2Sum at the bottom, O(n^(k−1)) · prune: skip `i` when the smallest possible sum is already > target.
- **Practice:** `01-Arrays/02-Two-Pointers/code/FourSum.java` · run: `java FourSum.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public List<List<Integer>> fourSum(int[] nums, int target) {
>         Arrays.sort(nums);
>         List<List<Integer>> res = new ArrayList<>();
>         int n = nums.length;
>         for (int i = 0; i < n - 3; i++) {
>             if (i > 0 && nums[i] == nums[i - 1]) continue;
>             for (int j = i + 1; j < n - 2; j++) {
>                 if (j > i + 1 && nums[j] == nums[j - 1]) continue; // j > i + 1, not j > 0
>                 int left = j + 1, right = n - 1;
>                 while (left < right) {
>                     long sum = (long) nums[i] + nums[j] + nums[left] + nums[right]; // avoid int overflow
>                     if (sum == target) {
>                         res.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
>                         left++;
>                         right--;
>                         while (left < right && nums[left] == nums[left - 1]) left++;
>                         while (left < right && nums[right] == nums[right + 1]) right--;
>                     }
>                     else if (sum < target) left++;
>                     else right--;
>                 }
>             }
>         }
>         return res;
>     }
> }
> ```

### LC 11 · Container With Most Water · 🟡 Medium
[Link](https://leetcode.com/problems/container-with-most-water/) · Confidence: ✅

- **Key insight:** start with the widest container (both ends) and always move the **shorter** line inward. The shorter line limits the height, so keeping it while the width shrinks can never give a bigger area.
- **Approach:**
  1. `left = 0`, `right = n − 1`, `best = 0`.
  2. Area = `min(height[left], height[right]) × (right − left)` → update `best`.
  3. Move the shorter side inward (`left++` or `right--`). Loop while `left < right`.
- **Brute → Optimal:** O(n²) every pair of lines → O(n) two pointers from both ends.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** only two lines, all the same height, zero heights, the best pair in the middle, strictly increasing heights.
- **Clarifying questions:** at least two lines? Can heights be zero? Return the area or the two indices?
- **Follow-ups:** why is moving the shorter side safe → every container it still makes is narrower and no taller, so all of them are worse · total water trapped between all bars → Trapping Rain Water (LC 42), also two pointers.
- **Practice:** `01-Arrays/02-Two-Pointers/code/ContainerWithMostWater.java` · run: `java ContainerWithMostWater.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int maxArea(int[] height) {
>         int left = 0, right = height.length - 1, best = 0;
>         while (left < right) {
>             best = Math.max(best, Math.min(height[left], height[right]) * (right - left));
>             if (height[left] < height[right]) left++;   // the shorter side can't do better → drop it
>             else right--;
>         }
>         return best;
>     }
> }
> ```

### LC 80 · Remove Duplicates from Sorted Array II · 🟡 Medium
[Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) · Confidence: ⚠️

- **Key insight:** the array is sorted, so equal values sit next to each other. Keep `nums[read]` only if it differs from the value two slots back in the kept prefix, `nums[write − 2]`. That allows at most two copies of each value.
- **Approach:**
  1. `write = 0` (next slot for a kept element).
  2. For each `read`: if `write < 2` or `nums[read] != nums[write − 2]`, copy it to `nums[write++]`.
  3. Return `write` (the new length). Only the first `write` slots matter.
- **Brute → Optimal:** count each value with a HashMap, then rebuild a new list, O(n) space → compare with `write − 2` in place, O(1) space.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single element, two elements, all the same (`[4,4,4,4]` → 2), no duplicates, runs of three at the end, negatives and zeros.
- **Clarifying questions:** is the array sorted ascending? Must I change it in place and return the length? Do the slots after the length matter?
- **Follow-ups:** at most `k` copies → compare with `nums[write − k]` and check `write < k` · `k = 1` → Remove Duplicates from Sorted Array (LC 26) · unsorted input → sort first (O(n log n)), or count with a HashMap and rebuild (O(n) space).
- **Practice:** `01-Arrays/02-Two-Pointers/code/RemoveDuplicatesFromSortedArrayII.java` · run: `java RemoveDuplicatesFromSortedArrayII.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int removeDuplicates(int[] nums) {
>         int write = 0;                                 // next slot to fill
>         for (int read = 0; read < nums.length; read++) {
>             // sorted → equal values are adjacent; differing from nums[write - 2] means fewer than 2 copies kept so far
>             if (write < 2 || nums[read] != nums[write - 2]) nums[write++] = nums[read];
>         }
>         return write;
>     }
> }
> ```

### LC 881 · Boats to Save People · 🟡 Medium
[Link](https://leetcode.com/problems/boats-to-save-people/) · Confidence: ⚠️

- **Key insight:** sort, then the heaviest person always needs a boat. Pair them with the lightest person if the two fit. If even the lightest doesn't fit with the heaviest, nobody does, so the heaviest goes alone.
- **Approach:**
  1. Sort `people`. `light = 0`, `heavy = n − 1`, `boats = 0`.
  2. While `light <= heavy`: if `people[light] + people[heavy] <= limit`, the light one boards too → `light++`.
  3. Always `heavy--` and `boats++` (the heavy one leaves every time). Return `boats`.
- **Brute → Optimal:** try every way of pairing people, exponential → sort + greedy two pointers, O(n log n).
- **Complexity:** O(n log n) time (the sort) · O(1) extra space, apart from the sort itself
- **Edge cases:** one person, nobody can pair (`[4,4,4]`, limit 5 → 3), everyone pairs, odd count so one rides alone, a pair that hits the limit exactly.
- **Clarifying questions:** at most two people per boat? Is every weight ≤ `limit` (so everyone fits alone)? May I sort the input?
- **Follow-ups:** why is heaviest + lightest safe → if the lightest can't ride with the heaviest, no one can, and pairing the lightest with anyone else is never better (swap argument) · weights in a small range → counting sort, O(n + limit) · more than 2 per boat → no simple greedy; it becomes bin packing.
- **Practice:** `01-Arrays/02-Two-Pointers/code/BoatsToSavePeople.java` · run: `java BoatsToSavePeople.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int numRescueBoats(int[] people, int limit) {
>         Arrays.sort(people);
>         int light = 0, heavy = people.length - 1, boats = 0;
>         while (light <= heavy) {                       // <=: the last person alone still needs a boat
>             if (people[light] + people[heavy] <= limit) light++;   // the light one fits → shares the boat
>             heavy--;                                   // the heavy one always leaves
>             boats++;
>         }
>         return boats;
>     }
> }
> ```

### LC 31 · Next Permutation · 🟡 Medium
[Link](https://leetcode.com/problems/next-permutation/) · Confidence: ❌

- **Key insight:** from the right, find the first **dip** `nums[pivot] < nums[pivot + 1]`. Everything after the pivot is descending (already its largest order). Swap the pivot with the rightmost value bigger than it, then **reverse** the suffix so it becomes the smallest order.
- **Approach:**
  1. `pivot = n − 2`; move left while `nums[pivot] >= nums[pivot + 1]`.
  2. If `pivot >= 0`: from the end, find the first `nums[swapIdx] > nums[pivot]` and swap the two.
  3. Reverse `nums[pivot + 1 .. n − 1]`. If there was no pivot (the whole array is descending), this reverses everything → the smallest permutation.
- **Brute → Optimal:** generate every permutation in sorted order and take the next one, O(n! · n) → pivot + swap + reverse, O(n).
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single element, the last permutation (`[3,2,1]` → `[1,2,3]`), all equal (`[2,2,2]`), duplicates in the suffix (`[1,5,1]` → `[5,1,1]`), pivot in the middle.
- **Clarifying questions:** must it be in place with O(1) extra space? Can there be duplicates? If it's already the largest, do I wrap around to the smallest?
- **Follow-ups:** previous permutation → mirror it: find the first `nums[i] > nums[i + 1]`, swap with the rightmost smaller value, reverse · next greater number with the same digits (LC 556) → same steps on the digits, plus an overflow check · k-th permutation (LC 60) → factorial number system.
- **Practice:** `01-Arrays/02-Two-Pointers/code/NextPermutation.java` · run: `java NextPermutation.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public void nextPermutation(int[] nums) {
>         int pivot = nums.length - 2;
>         while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) pivot--;   // >=: equal values aren't a dip
>         if (pivot >= 0) {
>             int swapIdx = nums.length - 1;
>             while (nums[swapIdx] <= nums[pivot]) swapIdx--;             // rightmost value strictly bigger
>             swap(nums, pivot, swapIdx);
>         }
>         reverse(nums, pivot + 1, nums.length - 1);    // suffix was descending → ascending = smallest
>     }
>
>     private void swap(int[] nums, int a, int b) {
>         int temp = nums[a];
>         nums[a] = nums[b];
>         nums[b] = temp;
>     }
>
>     private void reverse(int[] nums, int left, int right) {
>         while (left < right) swap(nums, left++, right--);
>     }
> }
> ```

### LC 189 · Rotate Array · 🟡 Medium
[Link](https://leetcode.com/problems/rotate-array/) · Confidence: ✅

- **Key insight:** rotating right by `k` = reverse the whole array, then reverse the first `k` and the last `n − k` separately. Each reverse is opposite-ends two pointers, so it's in place with O(1) space.
- **Approach:**
  1. `k = k % n`. Rotating by `n` is a full turn, and `k` can be bigger than `n`.
  2. Reverse `nums[0 .. n − 1]` → the last `k` values are now at the front, but backwards.
  3. Reverse `nums[0 .. k − 1]` and `nums[k .. n − 1]` → both parts are back in their original order.
- **Brute → Optimal:** shift right by one, `k` times, O(n·k) → copy into a new array at `(i + k) % n`, O(n) time and O(n) space → three reverses, O(n) time and O(1) space.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** `k = 0`, `k = n` (no change), `k > n` (use `k % n`), single element, n = 2.
- **Clarifying questions:** rotate right or left? Can `k` be bigger than `n`, or 0? Must it be in place with O(1) extra space?
- **Follow-ups:** rotate left by `k` → the same as rotating right by `n − k` · another O(1)-space way → cyclic replacements, moving each value straight to `(i + k) % n` and following the cycle (count the moves, stop at `n`) · rotate a linked list (LC 61) → link the tail to the head, cut at `n − k`.
- **Practice:** `01-Arrays/02-Two-Pointers/code/RotateArray.java` · run: `java RotateArray.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public void rotate(int[] nums, int k) {
>         int n = nums.length;
>         k %= n;                         // k can be larger than n
>         reverse(nums, 0, n - 1);        // whole array
>         reverse(nums, 0, k - 1);        // first k = the values that wrapped around
>         reverse(nums, k, n - 1);        // the rest
>     }
>
>     private void reverse(int[] nums, int left, int right) {
>         while (left < right) {
>             int temp = nums[left];
>             nums[left++] = nums[right];
>             nums[right--] = temp;
>         }
>     }
> }
> ```

### LC 42 · Trapping Rain Water · 🔴 Hard
[Link](https://leetcode.com/problems/trapping-rain-water/) · Confidence: ✅

- **Key insight:** water above bar `i` is `min(maxLeft, maxRight) − height[i]`. With two pointers, move the side whose bar is shorter: the other side already has a wall at least that tall, so this side's own running max decides the water.
- **Approach:**
  1. `left = 0`, `right = n − 1`, `leftMax = rightMax = 0`, `water = 0`.
  2. While `left < right`: if `height[left] < height[right]`, update `leftMax`, add `leftMax − height[left]`, then `left++`.
  3. Otherwise do the same on the right side with `rightMax`, then `right--`. Return `water`.
- **Brute → Optimal:** for each bar, scan both sides for the max, O(n²) → prefix-max and suffix-max arrays, O(n) time and O(n) space → two pointers, O(n) time and O(1) space.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** fewer than 3 bars, strictly increasing or decreasing (no water), all zeros, a flat-bottom basin, the tallest bar in the middle.
- **Clarifying questions:** is every bar width 1? Can heights be 0? Can the array be empty?
- **Follow-ups:** why is moving the shorter side safe → the far side has a wall at least as tall, so `min(...)` is this side's max · monotonic stack version → fills the water layer by layer ([[04-Stack]]) · 2-D grid (LC 407) → min-heap from the border, BFS inward.
- **Practice:** `01-Arrays/02-Two-Pointers/code/TrappingRainWater.java` · run: `java TrappingRainWater.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int trap(int[] height) {
>         int left = 0, right = height.length - 1;
>         int leftMax = 0, rightMax = 0, water = 0;
>         while (left < right) {
>             if (height[left] < height[right]) {         // right wall is taller → leftMax decides
>                 leftMax = Math.max(leftMax, height[left]);   // update first, so the water is never negative
>                 water += leftMax - height[left];
>                 left++;
>             } else {
>                 rightMax = Math.max(rightMax, height[right]);
>                 water += rightMax - height[right];
>                 right--;
>             }
>         }
>         return water;
>     }
> }
> ```

## Pitfalls
- `while (left <= right)` in pair problems → the same element is used twice.
- Forgetting to sort first → the move rule has no meaning.
- Sorting loses the original indices → if they're needed, store `(value, index)` pairs or use a HashMap.
- Sorting pairs with `(a, b) -> a[0] - b[0]` → overflows for values near ±10⁹. Use `Integer.compare(a[0], b[0])`.
- Fix-one + pair-sum: skip duplicate values for **both** the outer and inner pointers, or the output repeats.
- Merge Sorted Array: merging from the front overwrites `nums1` values before they're read → fill from the back.
- Merge Sorted Array: dropping the `i >= 0` guard → out of bounds once `nums1` runs out (for example `m = 0`).
- 3Sum: forgetting `Arrays.sort(nums)` → the pointer moves are meaningless and triplets are missed.
- 3Sum: after a match, `k++` instead of `k--` → `k` moves outward and `nums[k + 1]` goes out of bounds. Both pointers move **inward**.
- Dutch flag: moving `mid` after swapping with `high` → the swapped-in value is never checked.
- 4Sum: the second loop's duplicate skip is `j > i + 1`, not `j > 0`, or valid answers like `[0,0,0,0]` get skipped.
- 4Sum: add the sum up as a `long`. Four values near 10⁹ overflow an `int`.
- Two Sum II: returning 0-based indices → the answer must be 1-indexed (`left + 1`, `right + 1`).
- Move Zeroes: overwriting `nums[write] = nums[read]` without a swap or a zero-fill pass → the tail keeps old non-zero values.
- Valid Triangle: fixing the **smallest** side instead of the largest → the move rule breaks. Also `>=` instead of `>`: `a + b == c` is a flat line, not a triangle.
- Valid Triangle: `count++` on a match instead of `count += right − left` → undercounts.
- Container: moving the **taller** line → the area can only shrink, and the best pair is skipped. Always move the shorter one.
- Remove Duplicates II: comparing with `nums[write − 1]` instead of `nums[write − 2]` → only one copy survives, the same as LC 26.
- Valid Palindrome II: on a mismatch, trying only one side (only `left + 1`) → fails on `"cbbcc"`, where the right character is the one to delete. Check both sides.
- Assign Cookies: when the cookie is too small, moving the **child** pointer → that child is skipped for good (`g=[2,2,2]`, `s=[1,2,2]` gives 0, not 2). Drop the cookie instead.
- Boats: `while (light < heavy)` → the last person left alone never gets a boat (`[5]` gives 0, not 1). Use `<=`.
- Next Permutation: pivot search with `>` instead of `>=` → equal neighbours count as a dip, and `[2,2,2]` runs off the array. Use `>=`.
- Next Permutation: swap search with `<` instead of `<=` → you swap with an **equal** value (`[1,5,1]` gives `[1,1,5]`, not `[5,1,1]`). The swap value must be strictly bigger.
- Rotate Array: forgetting `k %= n` → `k > n` makes `reverse(0, k − 1)` run past the end of the array.
- Rotate Array: reversing the parts in the wrong order (parts first, then the whole) rotates **left**, not right.
- Trapping Rain Water: adding `leftMax − height[left]` **before** updating `leftMax` → negative water when the bar is a new max. Update the max first.

## Related
- [[01-Linear-Scan]]: sibling Arrays sub-topic; use a HashMap when the input is unsorted and indices matter.
- [[03-Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy|LC 1 Two Sum (HashMap)]]: unsorted + indices needed → HashMap beats [[#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy|sort + two pointers]] (the sorted version is [[#LC 167 · Two Sum II · 🟡 Medium|LC 167 Two Sum II]]).
- [[02-Sliding-Window]]: two pointers moving the same way over a contiguous window.
- [[06-Fast-Slow-Pointers]]: the same idea on linked lists (cycle, middle).
- [[11-Greedy]]: [[#LC 455 · Assign Cookies · 🟢 Easy|LC 455 Assign Cookies]] and [[#LC 881 · Boats to Save People · 🟡 Medium|LC 881 Boats to Save People]] are also greedy problems (sort, then match greedily).
- [[04-Stack]]: [[#LC 42 · Trapping Rain Water · 🔴 Hard|LC 42 Trapping Rain Water]] can also be solved with a monotonic stack.
