
import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] strs = s.split(" ");

        if (pattern.length() != strs.length)
            return false;

        Map<Character, String> map = new HashMap<>();

        for (int i = 0; i < strs.length; i++) {
            if (map.containsKey(pattern.charAt(i)) && !map.get(pattern.charAt(i)).equals(strs[i]))
                return false;
            if (!map.containsKey(pattern.charAt(i)) && map.containsValue(strs[i]))
                return false;
            map.put(pattern.charAt(i), strs[i]);
        }

        return true;
    }
}