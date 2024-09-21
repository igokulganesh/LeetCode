import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    /*
     * Sorting Solution
     * Time: O(nlogn)
     * Space: O(1)
     */
    public boolean isAnagram_usingSort(String s, String t) {
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();

        Arrays.sort(sArr);
        Arrays.sort(tArr);
        return Arrays.equals(sArr, tArr);
    }

    /*
     * Hash Map Solution
     * Time: O(n)
     * Space: O(n)
     */
    public boolean isAnagram_usingHashTable(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();

        for (Character c : s.toCharArray())
            map.merge(c, 1, Integer::sum);

        for (Character c : t.toCharArray()) {
            if (!map.containsKey(c))
                return false;
            map.merge(c, -1, Integer::sum);

            if (map.get(c) == 0)
                map.remove(c);
        }

        return map.isEmpty();
    }

    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        int[] lookup = new int[26];

        for (int i = 0; i < s.length(); i++) {
            lookup[s.charAt(i) - 'a']++;
            lookup[t.charAt(i) - 'a']--;
        }

        for (Integer x : lookup) {
            if (x != 0)
                return false;
        }

        return true;
    }

}