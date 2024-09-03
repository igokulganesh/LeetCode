
import java.util.HashMap;

class Solution {
    // Brute-Force Solution
    public int[] BruteForceSolution(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target)
                    return new int[] { i, j };
            }
        }
        return null;
    }

    public int[] twoSum(int[] nums, int target) {
        var map = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i]) && !map.get(target - nums[i]).equals(i)) {
                return new int[] { i, map.get(target - nums[i]) };
            }
            map.put(nums[i], i);
        }
        return null;
    };
}