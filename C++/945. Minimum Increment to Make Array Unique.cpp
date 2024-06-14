#include <bits/stdc++.h>

using namespace std;

// Time Limit Exeeds
int minIncrementForUnique(vector<int> &nums)
{
    unordered_set<int> set;

    int res = 0;
    for (int x : nums)
    {
        while (set.find(x) != set.end())
        {
            x++;
            res++;
        }
        set.insert(x);
    }

    return res;
}

// Optimal Solution Using Sorting
int minIncrementForUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            res += nums[i - 1] - nums[i] + 1;
            nums[i] += nums[i - 1] - nums[i] + 1;
        }
    }

    return res;
}

/*
3, 2, 1, 2, 1, 7
1, 2, 3, 4, 3, 7
   1  1  1

1, 1, 1, 1, 1, 10
   1  2  3  4  5
   1  2  3  4

*/