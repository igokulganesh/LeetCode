pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
    let n = matrix.len();
    let (mut a, mut b, mut c, mut d);

    for i in 0..n / 2 {
        for j in i..n - i - 1 {
            a = matrix[i][j];
            b = matrix[j][n - i - 1];
            c = matrix[n - i - 1][n - j - 1];
            d = matrix[n - j - 1][i];

            matrix[i][j] = d;
            matrix[j][n - i - 1] = a;
            matrix[n - i - 1][n - j - 1] = b;
            matrix[n - j - 1][i] = c;
        }
    }
}

/*

00 02 22 20
11

00 01 02
10 11 12
20 21 22


00 03 33 30
01 13 32 20
02 23 31 10
11 12 22 21

00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

*/
