#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0, z = 0;

    while (i < nums.size())
    {
        while (i < nums.size() and nums[i] == 0)
            i++;

        if (i < nums.size())
            nums[z++] = nums[i++];
    }

    while (z < nums.size())
        nums[z++] = 0;
}

void moveZeroes(vector<int> &nums)
{
    for (int i = 0, z = 0; i < nums.size(); i++)
        if (nums[i])
            swap(nums[z++], nums[i]);
}