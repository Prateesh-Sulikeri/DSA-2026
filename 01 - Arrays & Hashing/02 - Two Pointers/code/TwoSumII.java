// LC 167 · Two Sum II - Input Array Is Sorted · Medium
// Run: java TwoSumII.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

import java.util.Arrays;

public class TwoSumII {
    // ===== SOLUTION =====
    static class Solution {
        public int[] twoSum(int[] numbers, int target) {
            int left = 0, right = numbers.length - 1;
            while (left < right) {                         // < not <=: can't use one element twice
                int sum = numbers[left] + numbers[right];
                if (sum == target) return new int[]{left + 1, right + 1};  // 1-indexed answer
                if (sum < target) left++;                  // need bigger → move the small side up
                else right--;                              // need smaller → move the big side down
            }
            return new int[]{-1, -1};
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.twoSum(new int[]{2, 7, 11, 15}, 9), new int[]{1, 2});
        check("example 2", s.twoSum(new int[]{2, 3, 4}, 6), new int[]{1, 3});
        check("example 3 (negatives)", s.twoSum(new int[]{-1, 0}, -1), new int[]{1, 2});
        check("only two elements", s.twoSum(new int[]{1, 2}, 3), new int[]{1, 2});
        check("duplicates are the answer", s.twoSum(new int[]{1, 3, 3, 8}, 6), new int[]{2, 3});
        check("pair at the far right", s.twoSum(new int[]{1, 2, 5, 9, 10}, 19), new int[]{4, 5});
        check("answer in the middle", s.twoSum(new int[]{1, 4, 5}, 9), new int[]{2, 3});
        done();
    }

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
