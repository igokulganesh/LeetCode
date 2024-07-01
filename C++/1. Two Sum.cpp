#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Brutte Fore method
vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}

// Using Extra space to optimize the time complexity
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end() and map[target - nums[i]] != i)
        {
            return {i, map[target - nums[i]]};
        }
        map[nums[i]] = i;
    }
    return {-1, -1};
}

// If given array is sorted
vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1, sum;

    while (l < r)
    {
        sum = nums[l] + nums[r];

        if (sum == target)
            break;

        if (sum > target)
            l--;
        else
            r++;
    }
    return {l, r};
}