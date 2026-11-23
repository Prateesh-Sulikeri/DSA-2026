// LC 11 · Container With Most Water · Medium
// Run: java ContainerWithMostWater.java   (from "01 - Arrays & Hashing/02 - Two Pointers/code/")

public class ContainerWithMostWater {
    // ===== SOLUTION =====
    static class Solution {
        public int ContainerWithMostWater(int[] height) {
            int i=0;
            int j=height.length-1;
            int maxArea = 0;

            while (i<j) {
                int minHeight = Math.min(height[i], height[j]);
                int width = j - i;
                int area = minHeight * width;
                maxArea = Math.max(maxArea, area);

                if (height[i] < height[j])
                    i++;
                else
                    j--;
            } // TC: O(n) each step moves one pointer inward
            return maxArea;
        }
        // TC: O(n)
        // SC: O(1)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.ContainerWithMostWater(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7}), 49);
        check("example 2", s.ContainerWithMostWater(new int[]{1, 1}), 1);
        check("two lines, different heights", s.ContainerWithMostWater(new int[]{1, 2}), 1);
        check("all the same height", s.ContainerWithMostWater(new int[]{4, 4, 4, 4}), 12);
        check("best pair is in the middle", s.ContainerWithMostWater(new int[]{1, 2, 9, 9, 2, 1}), 9);
        check("zero heights", s.ContainerWithMostWater(new int[]{0, 0, 0}), 0);
        check("increasing", s.ContainerWithMostWater(new int[]{1, 2, 3, 4, 5}), 6);
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
