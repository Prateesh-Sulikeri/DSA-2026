// LC 217 · Contains Duplicate · Easy
// Run: java ContainsDuplicate.java   (from "01 - Arrays & Hashing/03 - Hashing/code/")

import java.util.Arrays;

public class ContainsDuplicate {
    // ===== SOLUTION =====
    static class Solution {
        public boolean containsDuplicate(int[] nums) {
            return Arrays.stream(nums).distinct().count() < nums.length; // SC: O(m), m = number of distinct values (distinct() keeps a set)
        } // TC: O(n)

        // TC: O(n)
        // SC: O(n)   (m <= n)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.containsDuplicate(new int[]{1, 2, 3, 1}), true);
        check("example 2", s.containsDuplicate(new int[]{1, 2, 3, 4}), false);
        check("example 3", s.containsDuplicate(new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}), true);
        check("single element", s.containsDuplicate(new int[]{7}), false);
        check("all the same", s.containsDuplicate(new int[]{5, 5, 5, 5}), true);
        check("repeat is the last element", s.containsDuplicate(new int[]{4, 9, 2, 8, 4}), true);
        check("negatives", s.containsDuplicate(new int[]{-1, -2, -3, -1}), true);
        check("int extremes, distinct", s.containsDuplicate(new int[]{Integer.MIN_VALUE, 0, Integer.MAX_VALUE}), false);
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
