#include <vector>

using namespace std;

// Normal SSolution
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % nums.size();

    vector<int> temp(n - k);

    for (int i = 0; i < n - k; i++)
        temp[i] = nums[i];

    for (int i = 0; i < k; i++)
        nums[i] = nums[n - k + i];

    for (int i = k; i < n; i++)
        nums[i] = temp[i - k];
}

/*
1,2,3,4,5,6,7
1,2,3,4
1 2 7 4 5 6 3

*/