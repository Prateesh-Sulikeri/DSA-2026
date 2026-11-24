// LC 31 · Next Permutation · Medium
// Run: java NextPermutation.java   (from "01-Arrays/02-Two-Pointers/code/")

import java.util.Arrays;

public class NextPermutation {
    // ===== SOLUTION =====
    static class Solution {
        public void nextPermutation(int[] nums) {
            // TODO: rearrange nums into the next greater permutation, in place, O(1) extra space
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{1, 2, 3}), "[1, 3, 2]");
        check("example 2 (last -> first)", run(new int[]{3, 2, 1}), "[1, 2, 3]");
        check("example 3", run(new int[]{1, 1, 5}), "[1, 5, 1]");
        check("single element", run(new int[]{1}), "[1]");
        check("two elements", run(new int[]{1, 2}), "[2, 1]");
        check("all the same", run(new int[]{2, 2, 2}), "[2, 2, 2]");
        check("pivot in the middle", run(new int[]{1, 3, 2}), "[2, 1, 3]");
        check("swap with rightmost larger", run(new int[]{2, 3, 1}), "[3, 1, 2]");
        check("duplicates in the suffix", run(new int[]{1, 5, 1}), "[5, 1, 1]");
        check("longer suffix to reverse", run(new int[]{1, 4, 5, 3, 2}), "[1, 5, 2, 3, 4]");
        done();
    }

    static String run(int[] nums) {
        new Solution().nextPermutation(nums);
        return Arrays.toString(nums);
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
