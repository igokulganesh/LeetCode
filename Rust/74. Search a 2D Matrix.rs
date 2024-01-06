use std::cmp::Ordering;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();

        let mut row = 0;
        while row < m {
            if matrix[row][n - 1] >= target {
                break;
            }
            row += 1;
        }

        if row < m {
            let mut low = 0;
            let mut high = n as isize - 1;

            while low <= high {
                let mid = low + (high - low) / 2;
                match matrix[row][mid as usize].cmp(&target) {
                    Ordering::Equal => return true,
                    Ordering::Less => low = mid + 1,
                    Ordering::Greater => high = mid - 1,
                }
            }
        }

        false
    }
}
