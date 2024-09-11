class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];

        int maxBar = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxBar = Math.max(maxBar, height[i]);
            left[i] = maxBar;
        }

        maxBar = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            maxBar = Math.max(maxBar, height[i]);
            right[i] = maxBar;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += Math.abs(height[i] - Math.min(left[i], right[i]));
        }

        return result;
    }
}
