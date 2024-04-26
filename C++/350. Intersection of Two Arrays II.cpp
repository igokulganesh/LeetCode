#include <bits/stdc++.h>

using namespace std;

// Approach 1: HashMAP
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // Optimizing Space
    if (nums1.size() > nums2.size())
        return intersect(nums2, nums1);

    unordered_map<int, int> map;
    vector<int> result;

    for (auto num : nums1)
        map[num]++;

    for (auto num : nums2)
        if (map[num]-- > 0)
            result.push_back(num);

    return result;
}

// Approach 2: Sorting
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;
    int i = 0, j = 0;

    while (i < nums1.size() and j < nums2.size())
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else
        {
            result.push_back(nums1[i]);
            j++, i++;
        }
    }
    return result;
}