---
tags: [dsa, pattern/arrays-hashing, pattern/arrays-hashing/prefix-sum]
status: learning
last_revised: 2026-11-24
---

# Prefix Sum

## TL;DR
- **What:** build running totals (sum or product) from the left, and from the right when needed, so any range or "everything except i" answer comes out in O(1).
- **When:** the same running total would be recomputed again and again: range-sum queries, "product of everything except i", "count subarrays with sum = k".
- **Complexity:** O(n) to build · O(1) per query · O(n) space (often O(1) extra by reusing the output array).

**Rule:** if you keep recomputing the same running total, compute it once from the left (and once from the right) and reuse it.

## Recognition Signals
- "Product / sum of all elements except `nums[i]`" → prefix × suffix (left pass, then right pass)
- "Without using the division operation" → prefix × suffix, not total ÷ `nums[i]`
- "Sum of the range `[l, r]`", asked many times → `prefix[r + 1] − prefix[l]`
- "Count subarrays with sum = k" → prefix sum + HashMap of how often each prefix has been seen, look up `prefix − k`
- "Pivot / equilibrium index" → left sum == total − left sum − `nums[i]`
- ✗ Not this when: max / min sum of a contiguous subarray → Kadane, [[01-Linear-Scan]]
- ✗ Not this when: all values are non-negative and the window has a size or sum limit → [[02-Sliding-Window]]

## Template
```java
// Prefix sums: prefix[i] = sum of nums[0..i-1], so the range [l, r] = prefix[r + 1] - prefix[l]
int[] prefix = new int[n + 1];                 // n + 1 slots: prefix[0] = 0 is the empty prefix
for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
```

```java
// Prefix × suffix: product of everything left of i, times everything right of i
int[] answer = new int[n];
answer[0] = 1;                                  // nothing to the left of index 0
for (int i = 1; i < n; i++) answer[i] = answer[i - 1] * nums[i - 1];
int right = 1;                                  // product of everything right of i
for (int i = n - 1; i >= 0; i--) {
    answer[i] *= right;
    right *= nums[i];                           // include nums[i] only AFTER using it
}
```

## Variants
| Variant | How it differs | Use when |
|---------|----------------|----------|
| **Prefix sum array** | `prefix[i + 1] = prefix[i] + nums[i]`, size n + 1 | many range-sum queries on a fixed array |
| **Prefix × suffix (two passes)** | left pass into the output, right pass with one running variable | "everything except i", no division allowed |
| **Prefix sum + HashMap** | map prefix value → count, look up `prefix − k` | count subarrays with sum = k (negatives allowed) |
| **2-D prefix sum** | rectangle sum by inclusion–exclusion | many sub-matrix sum queries |

## Problems

### LC 238 · Product of Array Except Self · 🟡 Medium
[Link](https://leetcode.com/problems/product-of-array-except-self/) · Confidence: ✅

- **Key insight:** `answer[i]` = (product of everything left of `i`) × (product of everything right of `i`), so a left pass and a right pass replace division.
- **Approach:**
  1. `answer[0] = 1`. Left pass: `answer[i] = answer[i − 1] × nums[i − 1]` → product of everything left of `i`.
  2. `right = 1`. Walk from the right: `answer[i] *= right`, then `right *= nums[i]`.
  3. Return `answer`. The output array doesn't count as extra space, so this is O(1) extra.
- **Brute → Optimal:** O(n²) multiply all the others for each index → O(n) total product ÷ `nums[i]` (banned, and breaks on zeros) → O(n) prefix × suffix, O(1) extra space.
- **Complexity:** O(n) time · O(1) extra space (the output array is not counted)
- **Edge cases:** one zero (only the zero's index is non-zero), two zeros (everything is 0), negatives, n = 2.
- **Clarifying questions:** is division allowed? Can the array contain zeros? Does the output array count as extra space? Is every product guaranteed to fit in a 32-bit int?
- **Follow-ups:** O(1) extra space → store the left products in the output, keep the right product in one variable · division allowed → product of the non-zeros + count the zeros (0 zeros: total ÷ x · 1 zero: only the zero's index gets the product · 2+ zeros: all 0) · products could overflow → `long` or modulo.
- **Practice:** `01-Arrays/04-Prefix-Sum/code/ProductOfArrayExceptSelf.java` · run: `java ProductOfArrayExceptSelf.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int[] productExceptSelf(int[] nums) {
>         int n = nums.length;
>         int[] answer = new int[n];
>         answer[0] = 1;
>         for (int i = 1; i < n; i++) answer[i] = answer[i - 1] * nums[i - 1]; // left products
>
>         int right = 1;
>         for (int i = n - 1; i >= 0; i--) {
>             answer[i] *= right;     // left × right
>             right *= nums[i];       // now include nums[i] for the indices further left
>         }
>         return answer;
>     }
> }
> ```

## Pitfalls
- Prefix sum array of size n instead of n + 1 → off-by-one on every range, and no slot for the empty prefix.
- Prefix × suffix: multiplying `right *= nums[i]` **before** `answer[i] *= right` → `nums[i]` ends up in its own answer.
- Starting the left pass at `answer[0] = nums[0]` instead of `1` → everything shifts by one element.
- Total ÷ `nums[i]` divides by zero when the array has a zero, and the problem bans division anyway.

## Related
- [[01-Linear-Scan]]: Kadane is "best prefix minus smallest earlier prefix" done in one pass; use it for max / min subarray sums.
- [[03-Hashing]]: "count subarrays with sum = k" pairs a prefix sum with a HashMap of seen prefixes.
- [[02-Sliding-Window]]: contiguous subarrays too, but only when every value is non-negative.
