import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        combine(n, k, 1, new LinkedList<>());
        return result;
    }

    public void combine(int n, int k, int i, List<Integer> cur) {
        if (k == cur.size()) {
            result.add(new ArrayList<>(cur));
            return;
        }

        for (int j = i; j <= n; j++) {
            cur.add(j);
            combine(n, k, j + 1, cur);
            cur.removeLast();
        }
    }
}