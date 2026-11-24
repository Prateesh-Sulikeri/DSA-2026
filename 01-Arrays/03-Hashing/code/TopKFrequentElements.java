// LC 347 · Top K Frequent Elements · Medium
// Run: java TopKFrequentElements.java   (from "01-Arrays/03-Hashing/code/")

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class TopKFrequentElements {
    // ===== SOLUTION =====
    static class Solution {
        public int[] topKFrequent(int[] nums, int k) {
            Map<Integer, Integer> freqMap = new HashMap<>(); // SC: O(m), m = number of distinct values

            for (int n : nums) {
                freqMap.put(n, freqMap.getOrDefault(n, 0) + 1); // TC: O(n)
            }

            PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> freqMap.get(a) - freqMap.get(b)); // SC: O(k)

            for (int num : freqMap.keySet()) {
                if (minHeap.size() < k) {
                    minHeap.offer(num);
                }

                else if (freqMap.get(num) > freqMap.get(minHeap.peek())) {
                    minHeap.poll();
                    minHeap.offer(num);
                }
            } // TC: O(m) × O(log k) -> O(m log k)

            int[] res = new int[k]; // SC: O(k)

            for (int i = 0 ; i < k ; i++) {
                res[i] = minHeap.poll();
            } // TC: O(k log k)   (k polls, each log k)

            return res;
        } // TC: O(n) + O(m log k) + O(k log k) && SC: O(m) + O(k) + O(k) wkt k <= m

        // TC: = O(n + mlogk)
        // SC: O(m)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();
        check("example 1", s.topKFrequent(new int[]{1, 1, 1, 2, 2, 3}, 2), new int[]{1, 2});
        check("example 2: single element", s.topKFrequent(new int[]{1}, 1), new int[]{1});
        check("example 3: mixed order", s.topKFrequent(new int[]{1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2), new int[]{1, 2});
        check("k = number of distinct values", s.topKFrequent(new int[]{4, 5, 6}, 3), new int[]{4, 5, 6});
        check("all the same", s.topKFrequent(new int[]{7, 7, 7}, 1), new int[]{7});
        check("negatives", s.topKFrequent(new int[]{-1, -1, 2}, 1), new int[]{-1});
        check("zero is the answer", s.topKFrequent(new int[]{3, 0, 1, 0}, 1), new int[]{0});
        check("one value dominates", s.topKFrequent(new int[]{5, 5, 5, 5, 9}, 1), new int[]{5});
        done();
    }

    // ---- test helpers ----
    static int passed = 0, total = 0;

    // Answer may come back in any order → compare sorted copies
    static void check(String name, int[] actual, int[] expected) {
        total++;
        int[] got = actual == null ? null : actual.clone(), want = expected.clone();
        if (got != null) Arrays.sort(got);
        Arrays.sort(want);
        boolean ok = Arrays.equals(got, want);
        if (ok) passed++;
        System.out.println((ok ? "PASS  " : "FAIL  ") + name + (ok ? "" : "  got " + Arrays.toString(got) + ", expected " + Arrays.toString(want)));
    }

    static void done() {
        System.out.println(passed + "/" + total + " passed");
        if (passed != total) System.exit(1);
    }
}
