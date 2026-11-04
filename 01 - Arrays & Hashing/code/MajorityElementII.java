// LC 229 · Majority Element II · Medium
// Run: java MajorityElementII.java   (or F5 in Zed)

import java.util.*;

public class MajorityElementII {
    // ===== SOLUTION =====
    static class Solution {
        public List<Integer> majorityElement(int[] nums) {
            Map<Integer, Integer> freqMap = new HashMap<>();
            List<Integer> res = new ArrayList<>();

            for (int n : nums) {
                int freq = freqMap.getOrDefault(n, 0) + 1;
                freqMap.put(n, freq);
            }

            for (Map.Entry<Integer, Integer> entry :  freqMap.entrySet()) {
                if (entry.getValue() > nums.length / 3)
                    res.add(entry.getKey());
            }

            return res;
        }

        public List<Integer> majpIntegers2(int[] nums) {
            int c1 = 0, c2 = 0, n1 = 0, n2 = 0;
            for (int x : nums) {
                if (x == c1) n1++;
                else if (x == c2) n2++;
                else if (n1 == 0) { c1 = x; n1 = 1; }
                else if (n2 == 0) { c2 = x; n2 = 1; }
                else { n1--; n2--; }
            }

            n1 = 0; n2 = 0;
            for (int x: nums) { if (x == c1) n1++; else if (x == c2) n2++;}
            List<Integer> res = new ArrayList<>();
            if(n1 > nums.length / 3) res.add(c1);
            if(n2 > nums.length / 3) res.add(c2);
            return res;
        }
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", sorted(s.majorityElement(new int[]{3, 2, 3})), List.of(3));
        check("single element", sorted(s.majorityElement(new int[]{1})), List.of(1));
        check("two elements", sorted(s.majorityElement(new int[]{1, 2})), List.of(1, 2));
        check("two majorities", sorted(s.majorityElement(new int[]{1, 1, 1, 3, 3, 2, 2, 2})), List.of(1, 2));
        check("no majority", sorted(s.majorityElement(new int[]{1, 2, 3, 4})), List.of());
        check("all zeros", sorted(s.majorityElement(new int[]{0, 0, 0})), List.of(0));
        check("candidate not a majority", sorted(s.majorityElement(new int[]{1, 2, 3, 1, 2, 4})), List.of());
        done();
    }

    static List<Integer> sorted(List<Integer> list) {
        List<Integer> copy = new ArrayList<>(list);
        Collections.sort(copy);
        return copy;
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
