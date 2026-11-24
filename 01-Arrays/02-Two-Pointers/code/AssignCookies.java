// LC 455 · Assign Cookies · Easy
// Run: java AssignCookies.java   (from "01-Arrays/02-Two-Pointers/code/")

import java.util.Arrays;

public class AssignCookies {
    // ===== SOLUTION =====
    static class Solution {
        public int findContentChildren(int[] g, int[] s) {

            int left = 0;
            int right = 0;

            Arrays.sort(g); // TC: O(g log g), g = number of children; SC: O(log g) sort stack
            Arrays.sort(s); // TC: O(s log s), s = number of cookies; SC: O(log s)

            while (left < g.length && right < s.length) {
                if (s[right] >= g[left]) {
                    left++;
                }

                right++;
            } // TC: O(g + s) both pointers only move forward

            return left;
        }
        // TC: O(g log g + s log s) sorting dominates
        // SC: O(log g + log s)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution sol = new Solution();
        check("example 1", sol.findContentChildren(new int[]{1, 2, 3}, new int[]{1, 1}), 1);
        check("example 2", sol.findContentChildren(new int[]{1, 2}, new int[]{1, 2, 3}), 2);
        check("no cookies", sol.findContentChildren(new int[]{1, 2}, new int[]{}), 0);
        check("unsorted input", sol.findContentChildren(new int[]{3, 1, 2}, new int[]{3, 1}), 2);
        check("all cookies too small", sol.findContentChildren(new int[]{5, 6}, new int[]{1, 2, 3}), 0);
        check("more cookies than children", sol.findContentChildren(new int[]{1, 1}, new int[]{1, 1, 1, 1}), 2);
        check("exact fit, reversed order", sol.findContentChildren(new int[]{2, 3}, new int[]{3, 2}), 2);
        check("one big cookie", sol.findContentChildren(new int[]{1, 2, 3}, new int[]{10}), 1);
        check("duplicates, small cookie first", sol.findContentChildren(new int[]{2, 2, 2}, new int[]{1, 2, 2}), 2);
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
