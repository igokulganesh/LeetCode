#include <bits/stdc++.h>

using namespace std;

// Basic Approach
int minCostClimbingStairs(vector<int> &cost, int i)
{
    if (cost.size() <= i)
        return 0;

    return cost[i] + min(minCostClimbingStairs(cost, i + 1), minCostClimbingStairs(cost, i + 2));
}

int minCostClimbingStairs(vector<int> &cost)
{
    return min(minCostClimbingStairs(cost, 0), minCostClimbingStairs(cost, 1));
}

// Top Down DP solution
int minCostClimbingStairs(vector<int> &cost, int i, vector<int> &cache)
{
    if (cost.size() <= i)
        return 0;

    if (cache[i] == -1)
        cache[i] = cost[i] + min(minCostClimbingStairs(cost, i + 1, cache), minCostClimbingStairs(cost, i + 2, cache));

    return cache[i];
}

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> cache(cost.size(), -1);
    return min(minCostClimbingStairs(cost, 0, cache), minCostClimbingStairs(cost, 1, cache));
}

// Bottom Up DP Solution
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    vector<int> cache(n);
    cache[0] = cost[0];
    cache[1] = cost[1];

    for (int i = 2; i < n; i++)
        cache[i] = cost[i] + min(cache[i - 1], cache[i - 2]);

    return min(cache[n - 1], cache[n - 2]);
}

// Bottom Up Solution with (Space Optimized)
int minCostClimbingStairs(vector<int> &cost)
{
    int a = cost[0];
    int b = cost[1];
    int c;

    for (int i = 2; i < cost.size(); i++)
    {
        c = cost[i] + min(a, b);
        a = b;
        b = c;
    }
    return min(a, b);
}
