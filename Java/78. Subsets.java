import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        subsets(nums, new LinkedList<>(), result, 0);

        return result;
    }

    private void subsets(int[] nums, List<Integer> cur, List<List<Integer>> result, int k) {
        result.add(new ArrayList<>(cur));

        for (int i = k; i < nums.length; i++) {
            cur.add(nums[i]);
            subsets(nums, cur, result, i + 1);
            cur.removeLast();
        }
    }

}