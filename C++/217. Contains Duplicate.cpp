#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set;

    for (auto num : nums)
    {
        if (set.find(num) != set.end())
            return true;
        set.insert(num);
    }
    return false;
}