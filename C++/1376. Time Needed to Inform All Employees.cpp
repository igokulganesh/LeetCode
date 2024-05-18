#include <bits/stdc++.h>

using namespace std;

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < n; i++)
        if (manager[i] != -1)
            graph[manager[i]].push_back(i);

    queue<pair<int, int>> que;
    que.push({headID, 0});

    int total_minutes = 0;
    int id, time_taken;

    while (!que.empty())
    {
        id = que.front().first;
        time_taken = que.front().second;
        que.pop();

        total_minutes = max(total_minutes, time_taken);

        for (int child : graph[id])
            que.push({child, time_taken + informTime[id]});
    }

    return total_minutes;
}