#include <bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> que;

    int row = grid.size();
    int col = grid[0].size();

    int time = 0;
    int fresh = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 2)
                que.push({i, j});

            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    int i, j, len;

    while (!que.empty())
    {
        len = que.size();
        while (len--)
        {

            i = que.front().first;
            j = que.front().second;
            que.pop();

            if (i + 1 < row and grid[i + 1][j] == 1)
            {
                que.push({i + 1, j});
                grid[i + 1][j] = 2;
                fresh--;
            }

            if (i - 1 >= 0 and grid[i - 1][j] == 1)
            {
                que.push({i - 1, j});
                grid[i - 1][j] = 2;
                fresh--;
            }

            if (j + 1 < col and grid[i][j + 1] == 1)
            {
                que.push({i, j + 1});
                grid[i][j + 1] = 2;
                fresh--;
            }

            if (j - 1 >= 0 and grid[i][j - 1] == 1)
            {
                que.push({i, j - 1});
                grid[i][j - 1] = 2;
                fresh--;
            }
        }

        if (!que.empty())
            time++;
    }

    return (fresh == 0) ? time : -1;
}
