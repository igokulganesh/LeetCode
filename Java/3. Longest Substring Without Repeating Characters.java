
import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int start = 0, longestStr = 0;

        for (int i = 0; i < s.length(); i++) {
            while (set.contains(s.charAt(i)))
                set.remove(s.charAt(start++));

            set.add(s.charAt(i));
            longestStr = Math.max(longestStr, i - start + 1);
        }

        return longestStr;
    }
}