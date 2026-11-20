---
tags: [dsa, pattern/arrays-hashing, pattern/arrays-hashing/linear-scan]
status: learning
last_revised: 2026-11-20
---

# Linear Scan

## TL;DR
- **What:** one pass over the array (linear scan), keeping O(1) state or a HashMap of what you've seen.
- **When:** the answer depends on counts, presence, or a running value → no sorting or nested loops needed.
- **Complexity:** typically O(n) time · O(1) space (scan) or O(n) space (HashMap).

**Rule:** if one pass plus a tiny piece of state can answer it, don't sort and don't nest loops.

## Recognition Signals
- "Element appearing more than n/2 times" → Boyer-Moore voting (Linear Scan)
- "Elements appearing more than n/k times" → Boyer-Moore with k−1 candidates (n/3 → 2 candidates)
- "Maximum / minimum sum of a contiguous subarray" → Kadane (Linear Scan)
- "Maximum product of a contiguous subarray" → Kadane tracking both max and min (negatives flip)
- "Find duplicate / pair / frequency" → HashMap or HashSet
- "Unsorted array, find two indices with sum = target" → checking every pair is only the O(n²) baseline; the O(n) answer is a HashMap → [[03 - Hashing]]
- Need the answer in O(n) time and O(1) space → track a running candidate/counter, not a map
- ✗ Not this when: the array must be searched by order or range → Binary Search / Two Pointers
- ✗ Not this when: "count subarrays with sum = k" → Prefix Sum + HashMap, Kadane only tracks the best sum

## Template
```java
// Linear scan with O(1) state (Boyer-Moore voting)
int candidate = 0, count = 0;
for (int num : nums) {
    if (count == 0) candidate = num;      // previous votes cancelled out → pick new candidate
    count += (num == candidate) ? 1 : -1; // same → vote for, different → vote against
}
return candidate;
```

```java
// Kadane: best subarray sum ending at each index
int current = nums[0], best = nums[0];       // start from nums[0], NOT 0 (all-negative arrays)
for (int i = 1; i < nums.length; i++) {
    current = Math.max(nums[i], current + nums[i]); // extend the run, or restart at nums[i]
    best = Math.max(best, current);
}
return best;
```

## Variants
| Variant | State kept | Use when |
|---------|-----------|----------|
| **Linear Scan (running state)** | a few variables (candidate, count, max, min) | O(1) space needed |
| **Boyer-Moore, k−1 candidates** | k−1 `(candidate, count)` pairs | elements > n/k times, O(1) space |
| **Kadane (running best)** | `current` run + `best` so far | max/min contiguous subarray sum |
| **Kadane (max + min)** | `maxP` and `minP` ending here | product subarray, negatives flip sign |
| **HashMap / HashSet** | frequency or seen-set | need lookups by value, O(n) space ok |

## Problems

### LC 1 · Two Sum (Brute Force) · 🟢 Easy
[Link](https://leetcode.com/problems/two-sum/) · Confidence: ✅

- **Key insight:** try every pair `(i, j)` with `j > i` and return the first one that adds up to `target`. No extra memory, but O(n²). It's the baseline you say out loud before optimising.
- **Approach:**
  1. Outer loop `i` from `0` to `n − 1`.
  2. Inner loop `j` from `i + 1`, so an element never pairs with itself and no pair is checked twice.
  3. `nums[i] + nums[j] == target` → return `{i, j}`.
- **Brute → Optimal:** O(n²) every pair (this one) → O(n log n) [[02 - Two Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy|sort + two pointers]] → O(n) [[03 - Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy|HashMap]].
- **Complexity:** O(n²) time · O(1) space
- **Edge cases:** the same value twice (`[3,3]`, target 6), negatives, the pair at the very end, an element that is exactly half of the target but appears once.
- **Clarifying questions:** is there always exactly one answer? Return indices or values? Can I use the same element twice? How big is n (is O(n²) fast enough)?
- **Follow-ups:** make it faster → [[03 - Hashing#LC 1 · Two Sum (HashMap) · 🟢 Easy|HashMap]], O(n) time · O(1) space required and O(n log n) is fine → heapsort the values, but you lose the indices · the array is sorted (LC 167) → two pointers, O(n) time and O(1) space.
- **Practice:** `01 - Arrays & Hashing/01 - Linear Scan/code/TwoSumBruteForce.java` · run: `java TwoSumBruteForce.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int[] twoSum(int[] nums, int target) {
>         for (int i = 0; i < nums.length; i++) {
>             for (int j = i + 1; j < nums.length; j++) {   // j > i: never pair i with itself
>                 if (nums[i] + nums[j] == target) return new int[]{i, j};
>             }
>         }
>         return new int[]{-1, -1};
>     }
> }
> ```

### LC 169 · Majority Element · 🟢 Easy
[Link](https://leetcode.com/problems/majority-element/) · Confidence: ⚠️

- **Key insight:** the majority element appears > n/2 times, so it survives pairing off every different pair (Boyer-Moore voting).
- **Approach:**
  1. Keep `candidate` and `count`.
  2. If `count == 0` → set `candidate = num`.
  3. Same as candidate → `count++`, else `count--`.
  4. Return `candidate` (majority is guaranteed to exist).
- **Brute → Optimal:** O(n²) count each element → O(n) HashMap counts, O(n) space → O(n) Boyer-Moore, O(1) space. (Sorting + `nums[n/2]` is O(n log n).)
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single element, all the same, majority at the very end (`[1,2,2]`).
- **Clarifying questions:** is a majority guaranteed to exist? Can I modify the array (sort it)? Is O(1) extra space required?
- **Follow-ups:** no guarantee → add a verify pass counting the candidate · elements > n/3 times → LC 229 · data is a stream → Boyer-Moore still works, one pass.
- **Practice:** `01 - Arrays & Hashing/01 - Linear Scan/code/MajorityElement.java` · run: `java MajorityElement.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int majorityElement(int[] nums) {
>         int candidate = 0, count = 0;
>         for (int num : nums) {
>             if (count == 0) candidate = num;
>             count += (num == candidate) ? 1 : -1;
>         }
>         return candidate; // guaranteed to exist, so no verify pass
>     }
> }
> ```

### LC 53 · Maximum Subarray (Kadane's Algorithm) · 🟡 Medium
[Link](https://leetcode.com/problems/maximum-subarray/) · Confidence: ❌

- **Key insight:** a running sum that goes negative only hurts the next element, so drop it and restart at the current element.
- **Approach:**
  1. `current = best = nums[0]`.
  2. For each next `num`: `current = max(num, current + num)` → extend the run or restart.
  3. `best = max(best, current)`.
  4. Return `best`.
- **Brute → Optimal:** O(n²) try every start/end (O(n³) if you re-sum) → O(n) one pass, O(1) space.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single element, all negative (answer is the largest single number), zeros.
- **Clarifying questions:** must the subarray be non-empty? Can all numbers be negative? Do you want the sum only, or the subarray too?
- **Follow-ups:** return the start/end indices → record `start` on each restart · circular array (LC 918) → max(normal Kadane, total − min subarray) · divide and conquer O(n log n).
- **Practice:** `01 - Arrays & Hashing/01 - Linear Scan/code/MaximumSubarray.java` · run: `java MaximumSubarray.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int maxSubArray(int[] nums) {
>         int current = nums[0], best = nums[0];
>         for (int i = 1; i < nums.length; i++) {
>             current = Math.max(nums[i], current + nums[i]);
>             best = Math.max(best, current);
>         }
>         return best;
>     }
> }
> ```

### LC 152 · Maximum Product Subarray · 🟡 Medium
[Link](https://leetcode.com/problems/maximum-product-subarray/) · Confidence: ❌

- **Key insight:** a negative flips max ↔ min, so track **both** the max and min product ending at each index (Kadane with two values).
- **Approach:**
  1. `maxP = minP = best = nums[0]`.
  2. For each `x`: `hi = max(x, maxP*x, minP*x)`, `lo = min(x, maxP*x, minP*x)`.
  3. Assign `maxP = hi`, `minP = lo` (compute both **before** overwriting).
  4. `best = max(best, maxP)`.
- **Brute → Optimal:** O(n²) product of every subarray → O(n) track max and min.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** single negative, zero resets both to 0 (via `x` option), even vs odd count of negatives, all zeros, `[-2, 0]`.
- **Clarifying questions:** can there be zeros and negatives? Does the product fit in an `int` (LeetCode guarantees 32-bit)? Must the subarray be non-empty?
- **Follow-ups:** product could overflow → use `long` or `double` · return the subarray itself · alternative: best of prefix and suffix running products, resetting to 1 after a zero.
- **Practice:** `01 - Arrays & Hashing/01 - Linear Scan/code/MaximumProductSubarray.java` · run: `java MaximumProductSubarray.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int maxProduct(int[] nums) {
>         int maxP = nums[0], minP = nums[0], best = nums[0];
>         for (int i = 1; i < nums.length; i++) {
>             int x = nums[i];
>             int hi = Math.max(x, Math.max(maxP * x, minP * x));
>             int lo = Math.min(x, Math.min(maxP * x, minP * x));
>             maxP = hi;
>             minP = lo;
>             best = Math.max(best, maxP);
>         }
>         return best;
>     }
> }
> ```

### LC 229 · Majority Element II · 🟡 Medium
[Link](https://leetcode.com/problems/majority-element-ii/) · Confidence: ❌

- **Key insight:** at most 2 elements can appear > n/3 times, so run Boyer-Moore with 2 candidates; a different third value cancels one vote from each.
- **Approach:**
  1. Keep `c1, n1, c2, n2`.
  2. For each `x`: matches `c1` → `n1++`; matches `c2` → `n2++`; `n1 == 0` → `c1 = x`; `n2 == 0` → `c2 = x`; else `n1--, n2--`.
  3. Second pass: count `c1` and `c2` for real.
  4. Keep each candidate only if its count `> n/3`.
- **Brute → Optimal:** O(n) HashMap counts, O(n) space → O(n) Boyer-Moore, O(1) space.
- **Complexity:** O(n) time · O(1) space
- **Edge cases:** n = 1 or 2, no majority at all (`[1,2,3,4]`), all zeros (initial candidate `0` must not fake a match), candidates that fail the verify pass.
- **Clarifying questions:** strictly more than ⌊n/3⌋? Does the output order matter? Is O(1) extra space required?
- **Follow-ups:** generalise to n/k → k − 1 candidates, O(nk) time · why at most 2 answers (3 × more than n/3 > n) · the two candidates can never be equal, so the verify counts stay separate.
- **Practice:** `01 - Arrays & Hashing/01 - Linear Scan/code/MajorityElementII.java` · run: `java MajorityElementII.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public List<Integer> majorityElement(int[] nums) {
>         int c1 = 0, c2 = 0, n1 = 0, n2 = 0;
>         for (int x : nums) {
>             if (x == c1) n1++;
>             else if (x == c2) n2++;
>             else if (n1 == 0) { c1 = x; n1 = 1; }
>             else if (n2 == 0) { c2 = x; n2 = 1; }
>             else { n1--; n2--; }
>         }
>         n1 = 0; n2 = 0;
>         for (int x : nums) { if (x == c1) n1++; else if (x == c2) n2++; }
>         List<Integer> res = new ArrayList<>();
>         if (n1 > nums.length / 3) res.add(c1);
>         if (n2 > nums.length / 3) res.add(c2);
>         return res;
>     }
> }
> ```

## Pitfalls
- Skipping the `count == 0` reset → candidate never changes.
- Boyer-Moore only works when the majority is **guaranteed**; otherwise add a second pass to verify the count > n/2.
- Incrementing/decrementing before the `count == 0` check → wrong candidate.
- n/3 version has **no guarantee** a majority exists → the verify pass is mandatory (unlike LC 169).
- Check `x == c1` / `x == c2` **before** the `n == 0` replacements, else the same value becomes both candidates.
- Kadane: initialising `best = 0` → wrong on all-negative arrays, use `nums[0]`.
- Kadane returns the **sum** only. To get the subarray indices, record `start` whenever you restart.
- Product Kadane: overwriting `maxP` before computing `minP` uses the wrong value, save both in temps first.
- Product Kadane: don't special-case zero, the `x` option in `max/min` already restarts the run.

## Related
- [[04 - Binary Search]]: alternative when the array is sorted.
- [[02 - Sliding Window]]: also contiguous subarrays, but needs non-negative values; Kadane handles negatives.
- [[03 - Prefix Sum]]: Kadane = best (prefix[i] − min earlier prefix); use prefix sums for "sum = k" counts.
- [[02 - Two Pointers]]: sibling Arrays sub-topic; use it when the array is sorted or you compare pairs from both ends.
