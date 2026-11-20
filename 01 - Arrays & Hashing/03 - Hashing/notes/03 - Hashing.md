---
tags: [dsa, pattern/arrays-hashing, pattern/arrays-hashing/hashing]
status: learning
last_revised: 2026-11-20
---

# Hashing

## TL;DR
- **What:** store what you've seen in a HashSet (presence) or HashMap (count / index / group), so every later lookup is O(1).
- **When:** the problem asks "have I seen this before?", "how many times?", or "which items belong together?".
- **Complexity:** O(n) time · O(n) space.

**Rule:** if the brute force compares every pair, trade O(n) memory for O(1) lookups with a HashSet or HashMap.

## Recognition Signals
- "Contains duplicate" / "any value appears twice" → HashSet, return on the first failed `add`
- "Count how often each value appears" → HashMap value → count (or `int[26]` for lowercase letters)
- "Unsorted array, find two indices with sum = target" → HashMap value → index, look up `target − x` before you put `x`
- "Same letters, rearranged" / "is t an anagram of s" → compare letter counts, `++` for one string and `--` for the other
- "Group items that are the same in some way" → HashMap key → list, where the key is the shared form
- ✗ Not this when: O(1) extra space is required and the array can be modified → sort, then compare neighbours
- ✗ Not this when: the input is already sorted → [[02 - Two Pointers]] or compare neighbours, no extra memory needed

## Template
```java
// Seen-set: stop at the first repeat
Set<Integer> seen = new HashSet<>();
for (int num : nums) {
    if (!seen.add(num)) return true;   // add() returns false when num is already in the set
}
return false;
```

```java
// Frequency map
Map<Integer, Integer> count = new HashMap<>();
for (int num : nums) {
    count.merge(num, 1, Integer::sum);  // count[num]++
}
```

## Variants
| Variant | Structure | Use when |
|---------|-----------|----------|
| **Seen-set** | `HashSet<T>` | only presence matters (duplicates, membership) |
| **Frequency map** | `HashMap<T, Integer>` | you need how many times each value appears |
| **Fixed-size count array** | `int[26]` / `int[128]` | the keys are small, known characters → faster than a map |
| **Sort instead** | none (sort in place) | O(1) extra space and the input may be changed → O(n log n) |

## Problems

### LC 217 · Contains Duplicate · 🟢 Easy
[Link](https://leetcode.com/problems/contains-duplicate/) · Confidence: ✅

- **Key insight:** a HashSet answers "have I seen this value?" in O(1), so one pass finds a repeat. `set.add(x)` returns `false` the moment `x` is already there.
- **Approach:**
  1. Create an empty `HashSet<Integer>`.
  2. For each number, call `seen.add(num)`.
  3. If `add` returns `false` → the number was already seen → return `true`.
  4. Loop ends with no repeat → return `false`.
- **Brute → Optimal:** O(n²) compare every pair → O(n log n) sort + compare neighbours, O(1) extra space → O(n) one pass with a HashSet.
- **Complexity:** O(n) time · O(n) space
- **Edge cases:** single element, all values the same, all values distinct, the repeat is the last element, negatives, `Integer.MIN_VALUE` / `MAX_VALUE`.
- **Clarifying questions:** how big can the array be (is O(n) memory fine)? Can I modify the input (sorting allowed)? Return just true/false, or the duplicate value?
- **Follow-ups:** O(1) extra space → sort and compare neighbours · duplicate within distance k (LC 219) → HashMap value → last index, or a sliding window set of size k · values in range `1..n` with one repeat (LC 287) → Floyd's cycle detection.
- **Practice:** `01 - Arrays & Hashing/03 - Hashing/code/ContainsDuplicate.java` · run: `java ContainsDuplicate.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public boolean containsDuplicate(int[] nums) {
>         Set<Integer> seen = new HashSet<>();
>         for (int num : nums) {
>             if (!seen.add(num)) return true;   // false → already in the set
>         }
>         return false;
>     }
> }
> ```

### LC 242 · Valid Anagram · 🟢 Easy
[Link](https://leetcode.com/problems/valid-anagram/) · Confidence: ✅

- **Key insight:** two strings are anagrams exactly when every letter appears the same number of times in both. Count up for `s`, count down for `t` in one `int[26]`; if every slot ends at 0, they match.
- **Approach:**
  1. If the lengths differ → return `false` straight away.
  2. Make `int[26] count`.
  3. For each index `i`: `count[s[i] − 'a']++` and `count[t[i] − 'a']--`.
  4. If any slot is not 0 → `false`, otherwise `true`.
- **Brute → Optimal:** O(n log n) sort both and compare → O(n) count letters in an `int[26]`, O(1) space.
- **Complexity:** count array O(n) time · O(1) space (26 slots, whatever the length) · sort O(n log n) time · O(n) space (two `char[]` copies)
- **Edge cases:** different lengths, same letters with different counts (`"aab"` vs `"abb"`), identical strings, single character, one letter repeated.
- **Clarifying questions:** only lowercase `a–z`, or Unicode / uppercase? Do spaces and punctuation count? Can the strings be empty?
- **Follow-ups:** Unicode input → `HashMap<Character, Integer>` instead of `int[26]` (or `int[128]` for ASCII) · group many words into anagram sets (LC 49) → HashMap with the sorted word (or the count array) as the key · find every anagram of `p` inside `s` (LC 438) → sliding window of the same counts.
- **Practice:** `01 - Arrays & Hashing/03 - Hashing/code/ValidAnagram.java` · run: `java ValidAnagram.java` from that folder (or F5 in Zed)

> [!example]- Code (Java) · Approach 1: sort both, compare
> ```java
> class Solution {
>     public boolean isAnagram(String s, String t) {
>         if (s.length() != t.length()) return false;
>
>         char[] sArr = s.toCharArray();
>         char[] tArr = t.toCharArray();
>
>         Arrays.sort(sArr);                 // anagrams become the same string once sorted
>         Arrays.sort(tArr);
>
>         return Arrays.equals(sArr, tArr);
>     }
> }
> ```

> [!example]- Code (Java) · Approach 2: count array (optimal)
> ```java
> class Solution {
>     public boolean isAnagram(String s, String t) {
>         if (s.length() != t.length()) return false;
>         int[] count = new int[26];
>         for (int i = 0; i < s.length(); i++) {
>             count[s.charAt(i) - 'a']++;    // letter in s → +1
>             count[t.charAt(i) - 'a']--;    // letter in t → −1
>         }
>         for (int c : count) {
>             if (c != 0) return false;      // some letter is unbalanced
>         }
>         return true;
>     }
> }
> ```

### LC 1 · Two Sum (HashMap) · 🟢 Easy
[Link](https://leetcode.com/problems/two-sum/) · Confidence: ✅

- **Key insight:** for each number, the partner you need is `target − nums[i]`. Keep a HashMap of value → index for everything seen so far, and look the partner up in O(1).
- **Approach:**
  1. Walk the array once with index `i`.
  2. If `target − nums[i]` is already in the map → return `{map.get(...), i}`.
  3. Otherwise put `nums[i] → i` in the map. Check **before** putting, so one element is never used twice.
- **Brute → Optimal:** O(n²) [[01 - Linear Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy|every pair]] → O(n log n) [[02 - Two Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy|sort + two pointers]], sorting shuffles the indices → O(n) one pass with a HashMap (this one).
- **Complexity:** O(n) time · O(n) space
- **Edge cases:** the same value twice (`[3,3]`, target 6), negatives, the pair at the very end, an element that is exactly half of the target but appears once.
- **Clarifying questions:** is there always exactly one answer? Return indices or values? Can I use the same element twice? Can values be negative?
- **Follow-ups:** the array is sorted (LC 167) → two pointers, O(1) space · return all pairs / unique pairs → sort + two pointers, skip duplicates · data stream (LC 170) → keep a count map, check on `find`.
- **Practice:** `01 - Arrays & Hashing/03 - Hashing/code/TwoSumHashMap.java` · run: `java TwoSumHashMap.java` from that folder (or F5 in Zed)

> [!example]- Code (Java)
> ```java
> class Solution {
>     public int[] twoSum(int[] nums, int target) {
>         Map<Integer, Integer> seen = new HashMap<>();   // value → index
>         for (int i = 0; i < nums.length; i++) {
>             Integer j = seen.get(target - nums[i]);
>             if (j != null) return new int[]{j, i};
>             seen.put(nums[i], i);                       // put AFTER the lookup: never pairs i with itself
>         }
>         return new int[]{-1, -1};
>     }
> }
> ```

## Pitfalls
- Calling `contains` and then `add` → two lookups for one; `add` already tells you if the value was there.
- Sorting to save memory changes the caller's array → ask before you modify the input.
- Building the whole set first and comparing `set.size() < nums.length` works, but never exits early.
- Two Sum: putting `nums[i]` in the map before the lookup → `[3, 2, 4]`, target 6 returns `[0, 0]` (the 3 pairs with itself).
- Anagram: skipping the length check → `"a"` vs `"ab"` slips through if you only loop over one string.
- Anagram: `int[26]` with `c − 'a'` breaks on uppercase or Unicode → `ArrayIndexOutOfBounds`; ask about the charset first.

## Related
- [[01 - Linear Scan]]: sibling Arrays sub-topic, for one pass with a running value.
- LC 1 Two Sum, the other two approaches: [[01 - Linear Scan#LC 1 · Two Sum (Brute Force) · 🟢 Easy|brute force]] (O(n²)) · [[02 - Two Pointers#LC 1 · Two Sum (Sort + Two Pointers) · 🟢 Easy|sort + two pointers]] (O(n log n)).
- [[02 - Two Pointers]]: sibling Arrays sub-topic; use it instead of a set when the input is sorted.
- [[02 - Sliding Window]]: "duplicate within distance k" keeps a set of only the last k values.
