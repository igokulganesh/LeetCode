pub fn max_sub_array(nums: Vec<i32>) -> i32 {
    let mut sum = i32::MIN;
    let mut cur_sum = 0;

    for i in 0..nums.len() {
        cur_sum += nums[i];
        sum = std::cmp::max(sum, cur_sum);
        if cur_sum < 0 {
            cur_sum = 0;
        }
    }

    sum
}
