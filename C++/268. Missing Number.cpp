#include <vector>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum1 = 0, sum2 = (n * (n + 1)) / 2;

    for (int x : nums)
        sum1 += x;

    return sum2 - sum1;
}