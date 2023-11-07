impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut left: usize = 0;
        let mut right: usize = numbers.len() - 1;

        while left <= right {
            match numbers[left] + numbers[right] {
                sum if sum == target => {
                    break;
                }
                sum if sum > target => {
                    right -= 1;
                }
                _ => {
                    left += 1;
                }
            }
        }

        vec![(left + 1) as i32, (right + 1) as i32]
    }
}