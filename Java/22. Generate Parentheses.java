import java.util.ArrayList;
import java.util.List;

class Solution {

    List<String> result = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        generate(new StringBuilder(), 0, 0, n);
        return result;
    }

    private void generate(StringBuilder cur, int open, int close, int n) {
        if (cur.length() == 2 * n) {
            result.add(cur.toString());
            return;
        }

        if (open < n) {
            cur.append('(');
            generate(cur, open + 1, close, n);
            cur.deleteCharAt(cur.length() - 1);
        }

        if (close < open) {
            cur.append(')');
            generate(cur, open, close + 1, n);
            cur.deleteCharAt(cur.length() - 1);
        }

    }
}