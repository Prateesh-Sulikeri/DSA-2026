// LC 42 · Trapping Rain Water · Hard
// Run: java TrappingRainWater.java   (from "01-Arrays/02-Two-Pointers/code/")


public class TrappingRainWater {
    // ===== SOLUTION =====
    static class Solution {
        public int trap(int[] height) {

            int left = 0;
            int right = height.length - 1;

            int water = 0;
            int leftMax = height[left];
            int rightMax = height[right];

            while (left < right) {
                if (leftMax < rightMax) {
                    left++;

                    leftMax = Math.max(leftMax, height[left]);

                    water += leftMax - height[left];
                } else {
                    right--;

                    rightMax = Math.max(rightMax, height[right]);

                    water += rightMax - height[right];
                }
            } // TC: O(n) each step moves one pointer inward
            return water;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.trap(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}), 6);
        check("example 2", s.trap(new int[]{4, 2, 0, 3, 2, 5}), 9);
        check("single bar", s.trap(new int[]{5}), 0);
        check("two bars", s.trap(new int[]{3, 3}), 0);
        check("all zeros", s.trap(new int[]{0, 0, 0}), 0);
        check("increasing (no right wall)", s.trap(new int[]{1, 2, 3, 4}), 0);
        check("decreasing (no left wall)", s.trap(new int[]{4, 3, 2, 1}), 0);
        check("one valley", s.trap(new int[]{3, 0, 3}), 3);
        check("walls of different height", s.trap(new int[]{2, 0, 5}), 2);
        check("tallest bar in the middle", s.trap(new int[]{2, 0, 4, 0, 1}), 3);
        check("flat-bottom basin", s.trap(new int[]{5, 1, 1, 1, 5}), 12);
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
