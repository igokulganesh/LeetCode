import java.util.List;
import java.util.ArrayList;

class Solution {

    List<List<Integer>> result;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        result = new ArrayList<>();

        combinationSum(candidates, 0, new ArrayList<>(), 0, target);

        return result;
    }

    public void combinationSum(int[] candidates, int i, List<Integer> cur, int sum, int target) {
        if (sum == target) {
            result.add(new ArrayList<>(cur));
            return;
        }

        if (sum > target || candidates.length == i)
            return;

        cur.add(candidates[i]);
        combinationSum(candidates, i, cur, sum + candidates[i], target);
        cur.removeLast();
        combinationSum(candidates, i + 1, cur, sum, target);

    }
}