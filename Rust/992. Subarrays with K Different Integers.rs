use std::collections::HashMap;

pub fn atmost_subarray_k_distinct(nums: &Vec<i32>, k: i32) -> i32 {
    let mut left: usize = 0;
    let mut map: HashMap<i32, usize> = HashMap::new();
    let mut distinct: i32 = 0;
    let mut result: usize = 0;

    for right in 0..nums.len() {
        map.entry(nums[right])
            .and_modify(|count| *count += 1)
            .or_insert(1);
        distinct += (*map.get(&nums[right]).unwrap() == 1) as i32;

        while distinct > k {
            map.entry(nums[left])
                .and_modify(|count| *count -= 1)
                .or_insert(0);
            distinct -= (*map.get(&nums[left]).unwrap() == 0) as i32;
            left += 1;
        }
        result += right - left + 1;
    }
    result as i32
}

impl Solution {
    pub fn subarrays_with_k_distinct(nums: Vec<i32>, k: i32) -> i32 {
        atmost_subarray_k_distinct(&nums, k) - atmost_subarray_k_distinct(&nums, k - 1)
    }
}