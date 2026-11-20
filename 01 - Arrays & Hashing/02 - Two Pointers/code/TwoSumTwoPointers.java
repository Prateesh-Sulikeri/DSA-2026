// LC 1 · Two Sum (Sort + Two Pointers) · Easy
// Run: java TwoSumTwoPointers.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class TwoSumTwoPointers {
    // ===== SOLUTION =====
    static class Solution {
        public int[] twoSum(int[] nums, int target) {
            return new int[]{-1, -1}; // TODO
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", sorted(s.twoSum(new int[]{2, 7, 11, 15}, 9)), new int[]{0, 1});
        check("example 2", sorted(s.twoSum(new int[]{3, 2, 4}, 6)), new int[]{1, 2});
        check("same value twice", sorted(s.twoSum(new int[]{3, 3}, 6)), new int[]{0, 1});
        check("negatives", sorted(s.twoSum(new int[]{-3, 4, 3, 90}, 0)), new int[]{0, 2});
        check("pair at the end", sorted(s.twoSum(new int[]{1, 5, 8, 2, 9}, 11)), new int[]{3, 4});
        done();
    }

    static int[] sorted(int[] a) { int[] c = a.clone(); Arrays.sort(c); return c; }

    // ---- test helpers ----
    static int passed = 0, total = 0;

    static void check(String name, Object actual, Object expected) {
        total++;
        boolean ok = java.util.Objects.deepEquals(actual, expected);
        if (ok) passed++;
        System.out.println((ok ? "PASS  " : "FAIL  ") + name + (ok ? "" : "  got " + Arrays.toString((int[]) actual) + ", expected " + Arrays.toString((int[]) expected)));
    }

    static void done() {
        System.out.println(passed + "/" + total + " passed");
        if (passed != total) System.exit(1);
    }
}
