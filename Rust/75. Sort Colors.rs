// simple solution
pub fn sort_colors(nums: &mut Vec<i32>) {
    let mut red = 0;
    let mut blue = 0;

    for i in 0..nums.len() {
        if nums[i] == 0 {
            red += 1;
        } else if nums[i] == 1 {
            blue += 1;
        }
    }

    let mut idx = 0;
    for _ in 0..red {
        nums[idx] = 0;
        idx += 1;
    }

    for _ in 0..blue {
        nums[idx] = 1;
        idx += 1;
    }

    for i in idx..nums.len() {
        nums[i] = 2;
    }
}

// binary search solution
pub fn sort_colors(nums: &mut Vec<i32>) {
    let mut low = 0;
    let mut mid = 0;
    let mut high = nums.len() - 1;

    while mid <= high {
        if nums[mid] == 0 {
            nums.swap(low, mid);
            low += 1;
            mid += 1;
        } else if nums[mid] == 1 {
            mid += 1;
        } else {
            nums.swap(high, mid);
            if high > 0 {
                high -= 1;
            } else {
                break;
            }
        }
    }
}
