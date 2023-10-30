use std::cmp::max;
use std::collections::HashSet;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut longest: i32 = 0;
        let mut start = 0;
        let mut set = HashSet::new();

        let chars: Vec<char> = s.chars().collect();

        for (i, char) in s.char_indices() {
            while set.contains(&char) {
                set.remove(&chars[start]);
                start += 1;
            }

            set.insert(&chars[i]);

            longest = max(longest, (i - start + 1) as i32);
        }

        longest
    }
}