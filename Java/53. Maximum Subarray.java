class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0, maxSum = nums[0];

        for (int num : nums) {
            sum += num;
            maxSum = Integer.max(maxSum, sum);
            sum = Integer.max(sum, 0);
        }

        return maxSum;
    }
}