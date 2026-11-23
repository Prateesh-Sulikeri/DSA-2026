// LC 75 · Sort Colors (Dutch National Flag) · Medium
// Run: java SortColors.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.Arrays;

public class SortColors {
    // ===== SOLUTION =====
    static class Solution {
        public void sortColors(int[] nums) {
            int i = 0;
            int j = 0;
            int k = nums.length - 1;

            while (j <= k) {
                if (nums[j] == 0) {
                    swap(nums, i, j);
                    i++;
                    j++;
                }
                else if (nums[j] == 2) {
                    swap(nums, j, k);
                    k--;
                }
                else {
                    j++;
                }
            } // TC: O(n) every step advances j or shrinks k, so at most n steps
        }
        // TC: O(n) single pass
        // SC: O(1)

        private void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{2, 0, 2, 1, 1, 0}), "[0, 0, 1, 1, 2, 2]");
        check("example 2", run(new int[]{2, 0, 1}), "[0, 1, 2]");
        check("single element", run(new int[]{1}), "[1]");
        check("all the same", run(new int[]{2, 2, 2}), "[2, 2, 2]");
        check("already sorted", run(new int[]{0, 1, 2}), "[0, 1, 2]");
        check("reverse sorted", run(new int[]{2, 2, 1, 1, 0, 0}), "[0, 0, 1, 1, 2, 2]");
        check("no 1s", run(new int[]{2, 0, 2, 0}), "[0, 0, 2, 2]");
        check("2 swapped in lands a 2", run(new int[]{2, 1, 2}), "[1, 2, 2]");
        check("0 at the end", run(new int[]{1, 1, 0}), "[0, 1, 1]");
        done();
    }

    static String run(int[] nums) {
        new Solution().sortColors(nums);
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
