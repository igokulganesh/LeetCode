
import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {

        Map<Character, Integer> map = new HashMap<>();

        for (Character c : magazine.toCharArray()) {
            map.merge(c, 1, Integer::sum);
        }

        for (Character c : ransomNote.toCharArray()) {
            if (!map.containsKey(c) || map.get(c) == 0)
                return false;
            map.merge(c, -1, Integer::sum);
        }

        return true;
    }
}