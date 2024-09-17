
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        int n = nums.length;
        int l, r, sum;
        for (int i = 0; i < n - 2; i++) {

            if (i == 0 || nums[i - 1] < nums[i]) {

                l = i + 1;
                r = n - 1;

                while (l < r) {
                    sum = nums[i] + nums[l] + nums[r];
                    if (sum == 0) {
                        result.add(List.of(nums[i], nums[l], nums[r]));

                        while (l < r && nums[l] == nums[l + 1])
                            l++;

                        while (l < r && nums[r] == nums[r - 1])
                            r--;

                        l++;
                        r--;

                    } else if (sum < 0)
                        l++;
                    else
                        r--;
                }
            }
        }

        return result;
    }
}