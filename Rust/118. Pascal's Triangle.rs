pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
    let mut pascal: Vec<Vec<i32>> = Vec::new();

    for i in 0..num_rows {
        pascal.push(Vec::new());
        for j in 0..i + 1 {
            if j == 0 || j == i {
                pascal[i as usize].push(1);
            } else {
                let value = pascal[(i - 1) as usize][(j - 1) as usize]
                    + pascal[(i - 1) as usize][j as usize];
                pascal[i as usize].push(value);
            }
        }
    }
    pascal
}
