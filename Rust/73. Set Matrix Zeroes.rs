// Best Solution Using Time: O(mn), Space: O(1)
pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
    let mut row_flag = false;
    let mut col_flag = false;

    for i in 0..matrix.len() {
        for j in 0..matrix[0].len() {
            if matrix[i][j] == 0 {
                matrix[i][0] = 0;
                matrix[0][j] = 0;

                if i == 0 {
                    row_flag = true;
                }
                if j == 0 {
                    col_flag = true;
                }
            }
        }
    }

    for i in 1..matrix.len() {
        for j in 1..matrix[0].len() {
            if matrix[i][0] == 0 || matrix[0][j] == 0 {
                matrix[i][j] = 0;
            }
        }
    }

    if row_flag {
        for j in 0..matrix[0].len() {
            matrix[0][j] = 0;
        }
    }

    if col_flag {
        for i in 0..matrix.len() {
            matrix[i][0] = 0;
        }
    }
}

// Simple Solution using Time: O(mn), Space: O(m + n)
pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
    let mut row: Vec<bool> = Vec::with_capacity(matrix.len());
    let mut col: Vec<bool> = Vec::with_capacity(matrix[0].len());

    for _ in 0..matrix.len() {
        row.push(false);
    }

    for _ in 0..matrix[0].len() {
        col.push(false);
    }

    for i in 0..matrix.len() {
        for j in 0..matrix[0].len() {
            if matrix[i][j] == 0 {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for i in 0..matrix.len() {
        for j in 0..matrix[0].len() {
            if row[i] || col[j] {
                matrix[i][j] = 0
            }
        }
    }
}
