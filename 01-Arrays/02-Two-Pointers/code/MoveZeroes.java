// LC 283 · Move Zeroes · Easy
// Run: java MoveZeroes.java   (from "01-Arrays/02-Two-Pointers/code/")

import java.util.Arrays;

public class MoveZeroes {
    // ===== SOLUTION =====
    static class Solution {
        public void moveZeroes(int[] nums) {
            int write = 0;                                 // next slot for a non-zero
            for (int read = 0; read < nums.length; read++) {
                if (nums[read] != 0) {
                    int temp = nums[write];                // swap, so the zero moves back to read
                    nums[write] = nums[read];
                    nums[read] = temp;
                    write++;
                }
            } // TC: O(n) single pass, each element swapped at most once
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{0, 1, 0, 3, 12}), "[1, 3, 12, 0, 0]");
        check("example 2 (single zero)", run(new int[]{0}), "[0]");
        check("single non-zero", run(new int[]{5}), "[5]");
        check("all zeros", run(new int[]{0, 0, 0}), "[0, 0, 0]");
        check("no zeros", run(new int[]{1, 2, 3}), "[1, 2, 3]");
        check("zeros already at the end", run(new int[]{1, 2, 0, 0}), "[1, 2, 0, 0]");
        check("zeros at the start", run(new int[]{0, 0, 1, 2}), "[1, 2, 0, 0]");
        check("keeps relative order", run(new int[]{4, 0, 2, 0, 1, 0, 3}), "[4, 2, 1, 3, 0, 0, 0]");
        check("negatives", run(new int[]{-1, 0, -2, 0}), "[-1, -2, 0, 0]");
        done();
    }

    static String run(int[] nums) {
        new Solution().moveZeroes(nums);
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
