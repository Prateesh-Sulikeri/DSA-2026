// LC 80 · Remove Duplicates from Sorted Array II · Medium
// Run: java RemoveDuplicatesFromSortedArrayII.java   (from "01-Arrays/02-Two-Pointers/code/")

import java.util.Arrays;

public class RemoveDuplicatesFromSortedArrayII {
    // ===== SOLUTION =====
    static class Solution {
        public int removeDuplicates(int[] nums) {
            int i = 0; // SC: O(1)
            for (int j=0 ; j<nums.length ; j++) {
                if (i<2 || nums[j] != nums[i-2]) {
                    nums[i] = nums[j];
                    i++;
                }
            } // TC: O(n) single pass

            return i;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{1, 1, 1, 2, 2, 3}), "5 [1, 1, 2, 2, 3]");
        check("example 2", run(new int[]{0, 0, 1, 1, 1, 1, 2, 3, 3}), "7 [0, 0, 1, 1, 2, 3, 3]");
        check("single element", run(new int[]{1}), "1 [1]");
        check("two elements", run(new int[]{1, 2}), "2 [1, 2]");
        check("two equal", run(new int[]{5, 5}), "2 [5, 5]");
        check("all the same", run(new int[]{4, 4, 4, 4}), "2 [4, 4]");
        check("no duplicates", run(new int[]{1, 2, 3, 4}), "4 [1, 2, 3, 4]");
        check("pairs only", run(new int[]{1, 1, 2, 2, 3, 3}), "6 [1, 1, 2, 2, 3, 3]");
        check("run of three at the end", run(new int[]{1, 2, 2, 2}), "3 [1, 2, 2]");
        check("negatives and zeros", run(new int[]{-3, -3, -3, -1, 0, 0, 0}), "5 [-3, -3, -1, 0, 0]");
        done();
    }

    static String run(int[] nums) {
        int k = new Solution().removeDuplicates(nums);
        return k + " " + Arrays.toString(Arrays.copyOf(nums, Math.max(k, 0)));
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
