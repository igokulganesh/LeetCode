#include <bits/stdc++.h>

using namespace std;

// Recursive (top-down)
int rob(vector<int> &nums, int i)
{
    if (i >= nums.size())
        return 0;

    return max(nums[i] + rob(nums, i + 2), rob(nums, i + 1));
}

int rob(vector<int> &nums)
{
    return rob(nums, 0);
}

// Recursive + memo (top-down)
int rob(vector<int> &nums, int i, vector<int> &cache)
{
    if (i >= nums.size())
        return 0;

    if (cache[i] == -1)
        cache[i] = max(nums[i] + rob(nums, i + 2, cache), rob(nums, i + 1, cache));

    return cache[i];
}

int rob(vector<int> &nums)
{
    vector<int> cache(nums.size(), -1);
    return rob(nums, 0, cache);
}

// Iterative + memo (bottom-up)
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    vector<int> cache(nums.size());

    for (int i = 2; i < nums.size(); i++)
        cache[i] = max(nums[i] + cache[i - 2], cache[i - 1]);

    return cache.back();
}

// Iterative + 2 variables (bottom-up)
int rob(vector<int> &nums)
{
    int prev1 = 0, prev2 = 0;
    for (int num : nums)
    {
        int temp = prev1;
        prev1 = max(prev1, num + prev2);
        prev2 = temp;
    }
    return prev1;
}