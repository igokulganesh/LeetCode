pub fn next_permutation(nums: &mut Vec<i32>) {
    let len = nums.len();
    let mut break_point = usize::MAX;

    if len < 2 {
        return;
    }

    // Find the breaking point
    /* Movement when highest point go down to lower */
    for i in (0..=len - 2).rev() {
        if nums[i] < nums[i + 1] {
            break_point = i;
            break;
        }
    }

    // if there is no breaking point then this must be the last perumutation simply return the 1'st perumutation
    if break_point == usize::MAX {
        nums.reverse();
        return;
    }

    // swap the break_point with higher than this from reverse order check
    for i in (break_point + 1..=len - 1).rev() {
        if nums[i] > nums[break_point] {
            nums.swap(break_point, i);
            break;
        }
    }

    // sort the rest of the array or reverse it since we know it is going increasing order
    let remaining_vec = &mut nums[break_point + 1..len];
    remaining_vec.reverse();
}
