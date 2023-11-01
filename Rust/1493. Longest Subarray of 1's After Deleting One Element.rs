use std::cmp::max;

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut longest: i32 = 0;
        let mut deleted: i8 = 0;

        for right in 0..nums.len() {
            deleted += (nums[right] == 0) as i8;

            while deleted > 1 {
                deleted -= (nums[left] == 0) as i8;
                left += 1;
            }
            longest = max(longest, (right - left) as i32);
        }
        longest
    }
}