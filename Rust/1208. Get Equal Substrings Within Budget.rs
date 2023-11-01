use std::cmp::max;

impl Solution {
    pub fn equal_substring(s: String, t: String, max_cost: i32) -> i32 {
        let mut max_sub: i32 = 0;
        let mut cost: i32 = 0;
        let mut left: usize = 0;
        let s_b: &[u8] = s.as_bytes();
        let t_b: &[u8] = t.as_bytes();

        for right in 0..s.len() {
            cost += (t_b[right] as i32 - s_b[right] as i32).abs();

            while cost > max_cost {
                cost -= (t_b[left] as i32 - s_b[left] as i32).abs();
                left += 1;
            }
            max_sub = max(max_sub, (right - left + 1) as i32);
        }
        max_sub
    }
}
