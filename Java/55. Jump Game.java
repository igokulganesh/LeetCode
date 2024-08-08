class Solution {

    /*
     * Basic Recursion Solution
     */
    public boolean canJump(int[] nums, int i) {
        if (nums.length - 1 <= i)
            return true;

        for (int k = 1; k <= nums[i]; k++) {
            if (canJump(nums, i + k))
                return true;
        }
        return false;
    }

    /*
     * DP Solution (TopDown approach)
     */
    private boolean canJump(int[] nums, int i, int[] dp) {
        if (nums.length - 1 <= i)
            return true;

        if (dp[i] == 0) {
            dp[i] = -1;
            for (int k = 1; k <= nums[i]; k++) {
                if (canJump(nums, i + k, dp)) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[i] == 1;
    }

    public boolean canJump(int[] nums) {
        int[] dp = new int[nums.length];
        return canJump(nums, 0, dp);
    }
}
