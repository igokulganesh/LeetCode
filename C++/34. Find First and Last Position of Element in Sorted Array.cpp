#include <vector>

using namespace std;

int findStart(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, mid;
    int res = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] >= target)
            high = mid - 1;
        else
            low = mid + 1;

        if (nums[mid] == target)
            res = mid;
    }
    return res;
}

int findEnd(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, mid;
    int res = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;

        if (nums[mid] == target)
            res = mid;
    }

    return res;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {findStart(nums, target), findEnd(nums, target)};
}