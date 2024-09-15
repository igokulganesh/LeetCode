class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0, r = numbers.length - 1;
        int m;

        while (l < r) {
            m = numbers[l] + numbers[r];

            if (m == target)
                break;
            else if (m > target)
                r--;
            else
                l++;
        }

        return new int[] { l + 1, r + 1 };
    }
}