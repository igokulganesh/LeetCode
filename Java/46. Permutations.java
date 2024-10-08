import java.util.ArrayList;
import java.util.List;

class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        List<Integer> permutaion = new ArrayList<>();
        for (int num : nums)
            permutaion.add(num);

        permute(permutaion, 0);
        return result;
    }

    private void permute(List<Integer> permutaion, int k) {
        if (k == permutaion.size() - 1) {
            result.add(new ArrayList<>(permutaion));
            return;
        }

        for (int i = k; i < permutaion.size(); i++) {
            swap(permutaion, i, k);
            permute(permutaion, k + 1);
            swap(permutaion, i, k);
        }
    }

    private void swap(List<Integer> nums, int a, int b) {
        int temp = nums.get(a);
        nums.set(a, nums.get(b));
        nums.set(b, temp);
    }
}