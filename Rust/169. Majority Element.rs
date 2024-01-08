// Sorting Technique
impl Solution {
    pub fn majority_element(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        nums[nums.len() / 2]
    }
}

// Hash Map technique
use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut map: HashMap<i32, usize> = HashMap::new();
        let mut majority: i32 = nums[0];
        let mut majority_count: usize = 0;

        for i in 0..nums.len() {
            map.entry(nums[i])
                .and_modify(|count| *count += 1)
                .or_insert(1);

            let cur_count = *map.get(&nums[i]).unwrap();

            if cur_count > majority_count {
                majority = nums[i];
                majority_count = cur_count;
            }

            if majority_count > nums.len() / 2 {
                break;
            }
        }

        majority
    }
}

// Optimal Solution
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut majority = nums[0];
        let mut count = 1;

        for i in 1..nums.len() {
            if count == 0 {
                majority = nums[i];
            }

            if majority == nums[i] {
                count += 1;
            } else {
                count -= 1;
            }
        }

        majority
    }
}
