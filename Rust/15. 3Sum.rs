use std::collections::HashSet;

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut set: HashSet<Vec<i32>> = HashSet::new();
        let mut left: usize;
        let mut right: usize;
        nums.sort();

        for i in 0..nums.len() {
            left = i + 1;
            right = nums.len() - 1;
            while left < right {
                match nums[i] + nums[left] + nums[right] {
                    sum if sum == 0 => {
                        set.insert(vec![nums[i], nums[left], nums[right]]);
                        right -= 1;
                        left += 1;
                    }
                    sum if sum > 0 => {
                        right -= 1;
                    }
                    _ => {
                        left += 1;
                    }
                }
            }
        }

        set.into_iter().collect()
    }
}

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut left: usize;
        let mut right: usize;
        nums.sort();

        for i in 0..nums.len() - 2 {
            // if first number is already larger then target then target no longer exists
            if nums[i] > 0 {
                break;
            }

            // skip the repeats
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }

            left = i + 1;
            right = nums.len() - 1;

            while left < nums.len() && left < right {
                match nums[i] + nums[left] + nums[right] {
                    sum if sum == 0 => {
                        result.push(vec![nums[i], nums[left], nums[right]]);

                        while left < nums.len() - 1 && nums[left] == nums[left + 1] {
                            left += 1;
                        }

                        while right > 0 && nums[right] == nums[right - 1] {
                            right -= 1;
                        }

                        right -= 1;
                        left += 1;
                    }
                    sum if sum > 0 => {
                        right -= 1;
                    }
                    _ => {
                        left += 1;
                    }
                }
            }
        }
        result
    }
}