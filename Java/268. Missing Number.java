
import java.util.Arrays;

class Solution {
    /*
     * HashMap Solution
     */
    public int missingNumber_1(int[] nums) {
        int n = nums.length + 1;
        boolean[] numbers = new boolean[n];

        for (int num : nums)
            numbers[num] = true;

        for (int i = 0; i < n; i++)
            if (numbers[i] == false)
                return i;

        return -1;
    }

    /*
     * Math Solution
     */
    public int missingNumber_2(int[] nums) {
        int n = nums.length;
        int actualSum = (n * (n + 1)) / 2;
        int sum = 0;

        for (int num : nums)
            sum += num;

        return actualSum - sum;
    }

    /*
     * Sorting Solution
     */
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);

        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }

        return n;
    }
}