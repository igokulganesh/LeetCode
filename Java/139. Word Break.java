import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

class Solution {

    /*
     * Brute Force Approach
     */
    public boolean wordBreak_1(String s, List<String> wordDict) {

        Set<String> set = new HashSet<>();

        for (String word : wordDict)
            set.add(word);

        return wordBreak(s, set);
    }

    private boolean wordBreak(String s, Set<String> set) {
        if (s.length() == 0)
            return true;

        for (int i = 1; i <= s.length(); i++) {
            if (set.contains(s.substring(0, i)) && wordBreak(s.substring(i), set))
                return true;
        }
        return false;
    }

    /*
     * DP Top Down Approach
     */
    public boolean wordBreak_2(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<>();
        Map<String, Boolean> cache = new HashMap<>();

        for (String word : wordDict) {
            dict.add(word);
            cache.put(word, true);
        }

        return wordBreak(s, dict, cache);
    }

    private boolean wordBreak(String s, Set<String> dict, Map<String, Boolean> cache) {
        if (s.length() == 0)
            return true;

        if (cache.containsKey(s))
            return cache.get(s);

        for (int i = 1; i <= s.length(); i++) {
            if (dict.contains(s.substring(0, i)) && wordBreak(s.substring(i), dict, cache)) {
                cache.put(s.substring(0, i), true);
                return true;
            }
        }
        cache.put(s, false);
        return false;
    }

    /*
     * DP Bottom Up Approach
     */
}