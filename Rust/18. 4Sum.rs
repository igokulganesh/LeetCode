// Time Limit Exceed
use std::collections::HashSet;

impl Solution {
    pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        nums.sort();
        let mut set: HashSet<Vec<i32>> = HashSet::new();

        if nums.len() < 4 {
            return Vec::new();
        }

        for i in 0..nums.len() - 3 {
            for j in i + 1..nums.len() - 2 {
                for k in j + 1..nums.len() - 1 {
                    for l in k + 1..nums.len() {
                        if nums[i] + nums[j] + nums[k] + nums[l] == target {
                            set.insert(vec![nums[i], nums[j], nums[k], nums[l]]);
                        }
                    }
                }
            }
        }
        set.into_iter().collect()
    }
}

impl Solution {
    pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        if nums.len() < 4 {
            return Vec::new();
        }

        let mut set: HashSet<Vec<i32>> = HashSet::new();
        let mut left: usize;
        let mut right: usize;

        nums.sort();

        for i in 0..nums.len() - 3 {
            // skip the repeats
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }

            for j in i + 1..nums.len() - 2 {
                left = j + 1;
                right = nums.len() - 1;

                while left < nums.len() && left < right {
                    match (nums[i] + nums[j] + nums[left] + nums[right]) as i64 {
                        sum if sum == target as i64 => {
                            set.insert(vec![nums[i], nums[j], nums[left], nums[right]]);

                            while left < nums.len() - 1 && nums[left] == nums[left + 1] {
                                left += 1;
                            }

                            while right > 0 && nums[right] == nums[right - 1] {
                                right -= 1;
                            }

                            right -= 1;
                            left += 1;
                        }
                        sum if sum > target as i64 => {
                            right -= 1;
                        }
                        _ => {
                            left += 1;
                        }
                    }
                }
            }
        }
        set.into_iter().collect()
    }
}
