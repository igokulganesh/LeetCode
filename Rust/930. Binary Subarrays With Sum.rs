pub fn atmost_subarray_sum(nums: &Vec<i32>, goal: i32) -> i32 {
    if goal < 0 {
        return 0;
    }

    let mut left: usize = 0;
    let mut sum: i32 = 0;
    let mut count: usize = 0;

    for right in 0..nums.len() {
        sum += nums[right];

        while sum > goal && left < nums.len() {
            sum -= nums[left];
            left += 1;
        }
        count += right - left + 1;
    }

    count as i32
}

impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        atmost_subarray_sum(&nums, goal) - atmost_subarray_sum(&nums, goal - 1)
    }
}