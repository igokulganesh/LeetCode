// Normal Two For loops Method
pub fn two_sum1(nums: Vec<i32>, target: i32) -> Vec<i32> {

    let mut result = Vec::new(); 
    
    for i in 0..nums.len() {
        for j in i+1..nums.len() {
            if nums[i] + nums[j] == target {
                result.push(i as i32); 
                result.push(j as i32);
                return  result;
            }
        }
    }
    result
}

// Binart Search method 
/* 
    This will not work since answer is expecting 
    index of the two element when We change the order 
    sorting it will endup with wrong index 
*/
pub fn two_sum2(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut result: Vec<i32> = Vec::new();

    let mut nums = nums.clone();
    nums.sort();

    let mut l = 0; 
    let mut r = nums.len()-1;
    
    while l < r {
      if nums[l] + nums[r] == target {
        result.push(l as i32); 
        result.push(r as i32);
        break;
      }  
      else if nums[l] + nums[r] > target {
        r -= 1; 
      }
      else {
        l += 1;
      }
    }
    result
}

// hashmap method
use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {

    let mut map: HashMap<i32, usize> = HashMap::new();
    let mut result: Vec<i32> = Vec::new();

    for i in 0..nums.len() {
        let key = target - nums[i]; 
        if map.contains_key(&key) {
            result.push(i as i32);
            result.push( *(map.get(&key).unwrap()) as i32);
            break;
        }
        else {
            map.insert(nums[i], i);
        }
    }
    result
}