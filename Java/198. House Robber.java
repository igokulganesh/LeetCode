class Solution {
    /*
     * Basic Recursion
     * Time: O(2^n)
     * Space: O(n)
     */
    public int rob_1(int[] nums) {
        return robUtil(nums, 0);
    }

    public int robUtil(int[] nums, int i) {
        if (i >= nums.length)
            return 0;

        return Math.max(nums[i] + robUtil(nums, i + 2), robUtil(nums, i + 1));
    }

    /*
     * DP Top Down Solution
     * Time: O(n)
     * Space: O(n)
     */
    public int rob_2(int[] nums) {
        int[] cache = new int[nums.length];
        for (int i = 0; i < cache.length; i++)
            cache[i] = -1;
        return robUtil(nums, 0, cache);
    }

    public int robUtil(int[] nums, int i, int[] cache) {
        if (i >= nums.length)
            return 0;

        if (cache[i] == -1) {
            int val1 = nums[i] + robUtil(nums, i + 2, cache);
            int val2 = robUtil(nums, i + 1, cache);
            cache[i] = Math.max(val1, val2);
        }

        return cache[i];
    }

    /*
     * DP Bottom Up Solution
     * Time: O(n)
     * Space: O(n)
     */
    public int rob_3(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return Math.max(nums[0], nums[1]);

        int[] cache = new int[nums.length];
        cache[0] = nums[0];
        cache[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            cache[i] = Math.max(nums[i] + cache[i - 2], cache[i - 1]);
        }
        return cache[n - 1];
    }

    /*
     * Optimal Solution
     * Time: O(n)
     * Space: O(1)
     */
    public int rob_4(int[] nums) {
        int n = nums.length;

        if (n == 1)
            return nums[0];
        if (n == 2)
            return Math.max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
        int cur = prev1;

        for (int i = 2; i < n; i++) {
            cur = Math.max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }

    /*
     * More Refined Solution From Above
     */
    public int rob(int[] nums) {
        int prev1 = nums[0], prev2 = 0;

        for (int num : nums) {
            int temp = prev1;
            prev1 = Math.max(num + prev2, prev1);
            prev2 = temp;
        }
        return prev1;
    }
}