#include <bits/stdc++.h>

using namespace std;

// Using 2 arrays to store the maxium
int trap(vector<int> &height)
{
    int n = height.size();

    if (n <= 2)
        return 0;

    vector<int> leftMax(n, 0), rightMax(n, 0);

    int maxT = height[0];
    for (int i = 1; i < n; i++)
    {
        maxT = max(maxT, height[i]);
        leftMax[i] = maxT;
    }

    maxT = height[n - 1];
    for (int j = n - 2; j > 0; j--)
    {
        maxT = max(maxT, height[j]);
        rightMax[j] = maxT;
    }

    int res = 0;
    for (int i = 1; i < n - 1; i++)
        res += min(leftMax[i], rightMax[i]) - height[i];

    return res;
}

// Space Optimized
int trap(vector<int> &height)
{
    int n = height.size();
    int leftMax = height[0], rightMax = height[n - 1];
    int i = 1, j = n - 2;
    int res = 0;

    while (i < j)
    {
        if (leftMax < rightMax)
        {
            if (height[i] <= leftMax)
                res += leftMax - height[i];
            else
                leftMax = height[i];
            i++;
        }
        else
        {
            if (height[j] <= rightMax)
                res += rightMax - height[j];
            else
                rightMax = height[j];
            j--;
        }
    }

    return res;
}
