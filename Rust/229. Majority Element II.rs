use std::collections::HashMap;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();

        for num in &nums {
            map.entry(*num).and_modify(|count| *count += 1).or_insert(1);
        }

        for entry in map.iter() {
            if *entry.1 > nums.len().div_euclid(3) {
                result.push(*entry.0)
            }
        }

        result
    }
}

use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();
        let mut set: HashSet<i32> = HashSet::new();

        for num in &nums {
            map.entry(*num).and_modify(|count| *count += 1).or_insert(1);

            let cur_count = *map.get(num).unwrap();

            if cur_count > nums.len().div_euclid(3) {
                set.insert(*num);
            }
        }

        set.into_iter().collect()
    }
}
