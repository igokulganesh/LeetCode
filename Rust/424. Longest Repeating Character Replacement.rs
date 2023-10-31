use std::cmp::max;
use std::collections::HashMap;

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut longest: usize = 0;
        let mut map: HashMap<char, usize> = HashMap::new();
        let mut left: usize = 0;
        let mut most_freq: usize = 0;
        let mut letters_to_change: usize;

        for (right, c) in s.char_indices() {
            map.entry(c).and_modify(|count| *count += 1).or_insert(1);

            most_freq = max(most_freq, *map.get(&c).unwrap());

            letters_to_change = (right - left + 1) - most_freq;

            if (right - left + 1) - most_freq > k as usize {
                map.entry(s.as_bytes()[left] as char)
                    .and_modify(|count| *count -= 1);
                left += 1;
            }

            longest = max(longest, right - left + 1);
        }

        longest as i32
    }
}