impl Solution {
    pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
        let mut result: i32 = 0;
        let mut left: usize = 0;
        let mut product: i32 = 1;

        for right in 0..nums.len() {
            product *= nums[right];

            while left <= right && product >= k {
                product /= nums[left];
                left += 1;
            }
            result += (right - left + 1) as i32;
        }
        result
    }
}