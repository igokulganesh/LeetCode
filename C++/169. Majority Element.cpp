#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> &v)
{
    unordered_map<int, int> m;

    for (int i = 0; i < v.size(); i++)
        m[v[i]]++;

    int major = v[0];
    int count = m[v[0]];

    for (auto i : m)
    {
        if (count <= i.second)
        {
            count = i.second;
            major = i.first;
        }
    }

    return major;
}

/*
    Above Approach have Space Complexity O(n)
    we have to optimize it

sort and return the middle element
Time: O(nLogn)
space: O(1)

*/

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

/*
    Best Solution using moor's voting Alg
*/
int majorityElement(vector<int> &nums)
{
    int count = 1;
    int major = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (count == 0)
            major = nums[i];

        if (major == nums[i])
            count++;
        else
            count--;
    }

    return major;
}
