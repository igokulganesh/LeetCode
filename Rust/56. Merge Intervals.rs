use std::cmp::{max, Ordering};

pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    pub fn compare(a: &Vec<i32>, b: &Vec<i32>) -> Ordering {
        if a[0] < b[0] {
            return Ordering::Less;
        } else if a[0] > b[0] {
            return Ordering::Greater;
        }
        Ordering::Equal
    }

    intervals.sort_by(compare);

    let mut result: Vec<Vec<i32>> = Vec::new();

    result.push(intervals[0].clone());

    for i in 1..intervals.len() {
        if result.last().unwrap()[1] >= intervals[i][0] {
            result.last_mut().unwrap()[1] = max(result.last().unwrap()[1], intervals[i][1])
        } else {
            result.push(intervals[i].clone())
        }
    }

    result
}
