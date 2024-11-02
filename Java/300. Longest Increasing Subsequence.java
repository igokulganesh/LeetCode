import java.util.Arrays;

class Solution {
    /*
     * Brute-force-method
     * Time: O(2^n)
     */
    public int lengthOfLIS_1(int[] nums) {
        int maxLIS = 0;
        for (int i = 0; i < nums.length; i++) {
            maxLIS = Math.max(maxLIS, lengthOfLIS(nums, i));
        }
        return maxLIS;
    }

    private int lengthOfLIS(int[] nums, int cur) {
        int maxLen = 1;

        for (int prev = 0; prev < cur; prev++) {
            if (nums[prev] < nums[cur]) {
                maxLen = Math.max(maxLen, 1 + lengthOfLIS(nums, prev));
            }
        }
        return maxLen;
    }

    /*
     * Top-down-dp
     * Time: O(n^2)
     * Space: O(n)
     */
    public int lengthOfLIS_2(int[] nums) {
        int maxLIS = 0;
        int[] cache = new int[nums.length];
        Arrays.fill(cache, -1);

        for (int i = 0; i < nums.length; i++) {
            maxLIS = Math.max(maxLIS, lengthOfLIS(nums, i, cache));
        }
        return maxLIS;
    }

    private int lengthOfLIS(int[] nums, int cur, int[] cache) {
        if (cache[cur] == -1) {
            int maxLen = 1;
            for (int prev = 0; prev < cur; prev++) {
                if (nums[prev] < nums[cur]) {
                    maxLen = Math.max(maxLen, 1 + lengthOfLIS(nums, prev, cache));
                }
            }
            cache[cur] = maxLen;
        }
        return cache[cur];
    }

    /*
     * Bottom-Up-DP
     * Time: O(n^2)
     * Space: O(n)
     */
    public int lengthOfLIS(int[] nums) {
        int[] cache = new int[nums.length];
        int maxLen = 0, localMax;

        for (int cur = 0; cur < nums.length; cur++) {
            localMax = 1;
            for (int prev = 0; prev < cur; prev++) {
                if (nums[prev] < nums[cur]) {
                    localMax = Math.max(localMax, 1 + cache[prev]);
                }
            }
            cache[cur] = localMax;
            maxLen = Math.max(maxLen, localMax);
        }

        return maxLen;
    }
}