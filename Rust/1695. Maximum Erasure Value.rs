use std::cmp::max;
use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut left = 0;
        let mut max_sum = 0;
        let mut set: HashSet<i32> = HashSet::new();

        for right in 0..nums.len() {
            while set.contains(&nums[right]) {
                sum -= nums[left];
                set.remove(&nums[left]);
                left += 1;
            }
            set.insert(nums[right]);
            sum += nums[right];
            max_sum = max(max_sum, sum);
        }
        max_sum
    }
}