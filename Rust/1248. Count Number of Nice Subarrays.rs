pub fn atmost_subarrays(nums: &Vec<i32>, k: i32) -> i32 {
    let mut left: usize = 0;
    let mut odd_cnt: i32 = 0;
    let mut result: usize = 0;

    for right in 0..nums.len() {
        odd_cnt += (nums[right] % 2 == 1) as i32;

        while odd_cnt > k {
            odd_cnt -= (nums[left] % 2 == 1) as i32;
            left += 1;
        }
        result += right - left + 1;
    }

    result as i32
}

impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        atmost_subarrays(&nums, k) - atmost_subarrays(&nums, k - 1)
    }
}