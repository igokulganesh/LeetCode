
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        char[] ch;

        for (String s : strs) {
            ch = s.toCharArray();
            Arrays.sort(ch);
            map.computeIfAbsent(String.valueOf(ch), k -> new ArrayList<>()).add(s);
        }

        for (List<String> sList : map.values())
            result.add(sList);

        return result;
    }
}