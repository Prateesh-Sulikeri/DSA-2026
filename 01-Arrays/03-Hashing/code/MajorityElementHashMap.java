// LC 169 · Majority Element (HashMap) · Easy
// Approach 1: frequency map, O(n) space · Approach 2: Boyer-Moore voting, O(1) space
// Run: java MajorityElementHashMap.java   (from "01-Arrays/03-Hashing/code/")

import java.util.HashMap;
import java.util.Map;

public class MajorityElementHashMap {
    // ===== SOLUTION =====
    static class Solution {
        // Approach 1: count each value, return the first one whose count passes n / 2
        public int majorityElement(int[] nums) {
            Map<Integer, Integer> freqMap = new HashMap<>(); // SC: O(m), m = number of distinct values

            for (int n : nums) {
                freqMap.put(n, freqMap.getOrDefault(n, 0) + 1);

                if (freqMap.get(n) > (nums.length / 2))   // strictly more than half → majority, stop early
                    return n;
            } // TC: O(n)

            return 0;   // unreachable when a majority is guaranteed
        }

        // TC: O(n)
        // SC: O(m)   (m <= n)

        // Approach 2: Boyer-Moore voting, each different value cancels one vote,
        // the majority (> n/2) still has votes left at the end
        public int majElem(int[] nums) {
            int candidate = 0, count = 0; // SC: O(1)

            for (int n : nums) {
                if (count == 0) candidate = n;          // no live candidate → take this one
                count += (n == candidate) ? 1 : -1;     // same → vote for, different → cancel one
            } // TC: O(n)

            return candidate;   // no verify pass: LC 169 guarantees a majority exists
        }

        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();

        // Approach 1: frequency map
        check("example 1", s.majorityElement(new int[]{3, 2, 3}), 3);
        check("example 2", s.majorityElement(new int[]{2, 2, 1, 1, 1, 2, 2}), 2);
        check("single element", s.majorityElement(new int[]{7}), 7);
        check("all the same", s.majorityElement(new int[]{4, 4, 4, 4}), 4);
        check("majority at the end", s.majorityElement(new int[]{1, 2, 2}), 2);
        check("negatives", s.majorityElement(new int[]{-3, -3, 5}), -3);
        check("strictly more than half (>= returns 1)", s.majorityElement(new int[]{1, 1, 2, 2, 2}), 2);

        // Approach 2: Boyer-Moore
        check("example 1", s.majElem(new int[]{3, 2, 3}), 3);
        check("example 2", s.majElem(new int[]{2, 2, 1, 1, 1, 2, 2}), 2);
        check("single element", s.majElem(new int[]{7}), 7);
        check("all the same", s.majElem(new int[]{4, 4, 4, 4}), 4);
        check("majority at the end", s.majElem(new int[]{1, 2, 2}), 2);
        check("negatives", s.majElem(new int[]{-3, -3, 5}), -3);
        check("candidate changes mid-way", s.majElem(new int[]{1, 1, 2, 2, 2}), 2);
        done();
    }

    // ---- test helpers ----
    static int passed = 0, total = 0;

    static void check(String name, Object actual, Object expected) {
        total++;
        boolean ok = java.util.Objects.deepEquals(actual, expected);
        if (ok) passed++;
        System.out.println((ok ? "PASS  " : "FAIL  ") + name + (ok ? "" : "  got " + actual + ", expected " + expected));
    }

    static void done() {
        System.out.println(passed + "/" + total + " passed");
        if (passed != total) System.exit(1);
    }
}
