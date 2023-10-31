use std::cmp::max;

impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {
        let mut longest: i32 = 0;
        let mut left: usize = 0;
        let mut z_cnt = 0;

        for right in 0..nums.len() {
            z_cnt += (nums[right] == 0) as i32;

            while z_cnt > k {
                z_cnt -= (nums[left] == 0) as i32;
                left += 1;
            }
            longest = max(longest, (right - left + 1) as i32);
        }
        longest
    }
}