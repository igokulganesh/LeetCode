#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int max_sum = nums[0], cur_sum;

    for (auto num : nums)
    {
        cur_sum += num;
        max_sum = max(max_sum, cur_sum);
        cur_sum = max(cur_sum, 0);
    }

    return max_sum;
}