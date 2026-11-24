// LC 128 · Longest Consecutive Sequence · Medium
// Run: java LongestConsecutiveSequence.java   (from "01-Arrays/03-Hashing/code/")

import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {
    // ===== SOLUTION =====
    static class Solution {
        public int longestConsecutive(int[] nums) {
            Set<Integer> seen = new HashSet<>(); // SC: O(m), one entry per distinct value

            for (int n: nums) {
                seen.add(n);
            } // TC: O(n), each HashSet add is O(1) average

            int maxCount = 0;

            for (int n: seen) { // TC: O(m), where m = number of distinct elements, m <= n
                if (!seen.contains(n-1)) {
                    int current = n;
                    int count = 1;

                    while (seen.contains(current + 1)) { // TC: O(k), where k = length of the run starting at n; only runs from a run start
                        current++;
                        count++;
                    }

                    maxCount = Math.max(maxCount, count);
                }
            } // TC: O(m) + O(m) = O(m). Every value is stepped over by the while loop at most once in total, because runs don't overlap and the k's add up to m (not O(m × k))
            return maxCount;
        }
        // n = length of nums, m = distinct values (m <= n)
        // TC: O(n) + O(m) = O(n)
        // SC: O(m) = O(n) worst case
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1 [100,4,200,1,3,2]", s.longestConsecutive(new int[]{100, 4, 200, 1, 3, 2}), 4);
        check("example 2 [0,3,7,2,5,8,4,6,0,1]", s.longestConsecutive(new int[]{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}), 9);
        check("example 3 [1,0,1,2]", s.longestConsecutive(new int[]{1, 0, 1, 2}), 3);
        check("empty array", s.longestConsecutive(new int[]{}), 0);
        check("single element", s.longestConsecutive(new int[]{7}), 1);
        check("all the same value", s.longestConsecutive(new int[]{5, 5, 5, 5}), 1);
        check("no two consecutive", s.longestConsecutive(new int[]{10, 30, 20}), 1);
        check("negatives cross zero", s.longestConsecutive(new int[]{-2, 1, -1, 0, 5}), 4);
        check("two runs, longer second", s.longestConsecutive(new int[]{1, 2, 10, 11, 12, 13}), 4);
        check("LC bounds -10^9 / 10^9", s.longestConsecutive(new int[]{1_000_000_000, -1_000_000_000, 999_999_999}), 2);
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
