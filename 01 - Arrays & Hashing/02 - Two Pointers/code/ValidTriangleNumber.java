// LC 611 · Valid Triangle Number · Medium
// Run: java ValidTriangleNumber.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.Arrays;

public class ValidTriangleNumber {
    // ===== SOLUTION =====
    static class Solution {
        public int triangleNumber(int[] nums) {
            int count = 0;
            int n = nums.length;
            Arrays.sort(nums);

            for (int k = n-1 ; k>=2 ; k--) {
                int i = 0;
                int j = k-1;

                while (j > i) {
                    if (nums[i] + nums[j] > nums[k]) {
                        count += j - i;
                        j--;
                    }

                    else {
                        i++;
                    }
                }
            }
            return count;
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        check("example 1", run(new int[]{2, 2, 3, 4}), 3);
        check("example 2", run(new int[]{4, 2, 3, 4}), 4);
        check("empty", run(new int[]{}), 0);
        check("fewer than 3", run(new int[]{1, 2}), 0);
        check("all zeros", run(new int[]{0, 0, 0}), 0);
        check("zero is never a side", run(new int[]{0, 1, 1, 1}), 1);
        check("all the same", run(new int[]{1, 1, 1, 1}), 4);
        check("equal sum is not a triangle", run(new int[]{1, 2, 3}), 0);
        check("unsorted input", run(new int[]{11, 4, 9, 6, 15, 18}), 10);
        done();
    }

    static int run(int[] nums) {
        return new Solution().triangleNumber(nums);
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
