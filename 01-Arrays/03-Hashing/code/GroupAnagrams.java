// LC 49 · Group Anagrams · Medium
// Approach 1: sorted word as the key, O(n · k log k) · Approach 2: letter counts as the key, O(n · k)
// Run: java GroupAnagrams.java   (from "01-Arrays/03-Hashing/code/")

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GroupAnagrams {
    // ===== SOLUTION =====
    static class Solution {
        // Approach 1: anagrams sort to the same string → use it as the key
        // n = number of words, k = length of the longest word
        public List<List<String>> groupAnagrams(String[] strs) {
            Map<String, List<String>> hash = new HashMap<>(); // SC: O(n × k), keys + grouped words

            for (String s : strs) {
                char[] cArr = s.toCharArray(); // SC: O(k)   (temporary copy, reused each word)
                Arrays.sort(cArr); // TC: O(k log k) per word
                String keyStr = new String(cArr);   // "eat", "tea" → "aet"   TC: O(k)

                hash.computeIfAbsent(keyStr, k -> new ArrayList<>()).add(s);   // make the list once, then append   TC: O(k) hash of key
            } // TC: O(n) × O(k log k) -> O(n k log k)

            return new ArrayList<>(hash.values());
        } // TC: O(n k log k) && SC: O(n k)

        // TC: O(n · k log k)
        // SC: O(n · k)

        // Approach 2: anagrams have the same letter counts → use the counts as the key (no sort)
        // n = number of words, k = length of the longest word
        public List<List<String>> grpAnagrams(String[] strs) {
            Map<List<Integer>, List<String>> hash = new HashMap<>(); // SC: O(n × k), 26-int keys are O(1) each + grouped words

            for (String str: strs) {
                int[] cArr = new int[26]; // SC: O(1)
                for (char c : str.toCharArray()) {
                    cArr[c - 'a']++;
                } // TC: O(k) per word
                // int[] can't be a key (equals/hashCode by reference); List<Integer> compares by value
                List<Integer> key = Arrays.stream(cArr).boxed().toList(); // TC: O(26) -> O(1)
                hash.computeIfAbsent(key, k -> new ArrayList<>()).add(str); // TC: O(26) hash -> O(1)
            } // TC: O(n) × O(k) -> O(n k)

            return new ArrayList<>(hash.values());
        } // TC: O(n k) && SC: O(n k)

        // TC: O(n · k)
        // SC: O(n · k)
    }

    // ===== TESTS =====
    public static void main(String[] args) {
        Solution s = new Solution();

        // Approach 1: sorted word as the key
        check("example 1", s.groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}),
                List.of(List.of("bat"), List.of("nat", "tan"), List.of("ate", "eat", "tea")));
        check("empty string", s.groupAnagrams(new String[]{""}), List.of(List.of("")));
        check("single word", s.groupAnagrams(new String[]{"a"}), List.of(List.of("a")));
        check("no anagrams", s.groupAnagrams(new String[]{"abc", "def", "ghi"}),
                List.of(List.of("abc"), List.of("def"), List.of("ghi")));
        check("all anagrams", s.groupAnagrams(new String[]{"abc", "bca", "cab"}),
                List.of(List.of("abc", "bca", "cab")));
        check("duplicate words", s.groupAnagrams(new String[]{"ab", "ba", "ab"}),
                List.of(List.of("ab", "ab", "ba")));
        check("same letters, different counts", s.groupAnagrams(new String[]{"aab", "abb"}),
                List.of(List.of("aab"), List.of("abb")));
        check("empty and non-empty", s.groupAnagrams(new String[]{"", "b", ""}),
                List.of(List.of("", ""), List.of("b")));


        // Approach 2: letter counts as the key
        check("example 1", s.grpAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}),
                List.of(List.of("bat"), List.of("nat", "tan"), List.of("ate", "eat", "tea")));
        check("empty string", s.grpAnagrams(new String[]{""}), List.of(List.of("")));
        check("single word", s.grpAnagrams(new String[]{"a"}), List.of(List.of("a")));
        check("no anagrams", s.grpAnagrams(new String[]{"abc", "def", "ghi"}),
                List.of(List.of("abc"), List.of("def"), List.of("ghi")));
        check("all anagrams", s.grpAnagrams(new String[]{"abc", "bca", "cab"}),
                List.of(List.of("abc", "bca", "cab")));
        check("duplicate words", s.grpAnagrams(new String[]{"ab", "ba", "ab"}),
                List.of(List.of("ab", "ab", "ba")));
        check("same letters, different counts", s.grpAnagrams(new String[]{"aab", "abb"}),
                List.of(List.of("aab"), List.of("abb")));
        check("empty and non-empty", s.grpAnagrams(new String[]{"", "b", ""}),
                List.of(List.of("", ""), List.of("b")));
        done();
    }

    // Groups can come back in any order → sort words inside each group, then sort the groups
    static List<List<String>> normalize(List<List<String>> groups) {
        if (groups == null) return null;
        List<List<String>> out = new ArrayList<>();
        for (List<String> g : groups) {
            List<String> copy = new ArrayList<>(g);
            copy.sort(null);
            out.add(copy);
        }
        out.sort((a, b) -> a.size() != b.size() ? a.size() - b.size() : a.toString().compareTo(b.toString()));
        return out;
    }

    // ---- test helpers ----
    static int passed = 0, total = 0;

    static void check(String name, List<List<String>> actual, List<List<String>> expected) {
        total++;
        List<List<String>> got = normalize(actual), want = normalize(expected);
        boolean ok = java.util.Objects.equals(got, want);
        if (ok) passed++;
        System.out.println((ok ? "PASS  " : "FAIL  ") + name + (ok ? "" : "  got " + got + ", expected " + want));
    }

    static void done() {
        System.out.println(passed + "/" + total + " passed");
        if (passed != total) System.exit(1);
    }
}
