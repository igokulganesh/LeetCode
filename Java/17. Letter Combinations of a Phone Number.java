import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    Map<Character, String> keys;
    List<String> result;

    public Solution() {
        result = new ArrayList<>();
        keys = new HashMap<>();
        keys.put('2', "abc");
        keys.put('3', "def");
        keys.put('4', "ghi");
        keys.put('5', "jkl");
        keys.put('6', "mno");
        keys.put('7', "pqrs");
        keys.put('8', "tuv");
        keys.put('9', "wxyz");
    }

    public List<String> letterCombinations(String digits) {
        if (digits.length() > 0)
            letterCombinations(digits, 0, new StringBuilder(digits.length()));
        return result;
    }

    public void letterCombinations(String digits, int i, StringBuilder cur) {
        if (i == digits.length()) {
            result.add(cur.toString());
            return;
        }

        for (char k : keys.get(digits.charAt(i)).toCharArray()) {
            cur.append(k);
            letterCombinations(digits, i + 1, cur);
            cur.deleteCharAt(i);
        }
    }
}