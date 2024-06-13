#include <bits/stdc++.h>

using namespace std;

// Binary Search Method
void sortColors(vector<int> &nums)
{
    int cur = 0, left = 0, right = nums.size() - 1;

    while (cur <= right)
    {
        if (nums[cur] == 0)
            swap(nums[cur++], nums[left++]);
        else if (nums[cur] == 2)
            swap(nums[cur], nums[right--]);
        else
            cur++;
    }
}

// 2-pass
void sortColors(vector<int> &nums)
{
    int white = 0, blue = 0, n = nums.size();

    for (int x : nums)
    {
        if (x == 0)
            white++;
        else if (x == 1)
            blue++;
    }

    int i = 0;
    while (i < white)
        nums[i++] = 0;

    while (i < blue)
        nums[i++] = 1;

    while (i < n)
        nums[i++] = 2;
}
