#include <bits/stdc++.h>

using namespace std;

/*
	DFS method to remove the visited island
	we can also use BFS (queue) to achieve same
*/

int row, col;

void numIslands(vector<vector<char>> &grid, int i, int j) // DFS
{
	if (i == row or j == col or i < 0 or j < 0 or grid[i][j] == '0')
		return;

	grid[i][j] = '0';

	numIslands(grid, i + 1, j);
	numIslands(grid, i - 1, j);
	numIslands(grid, i, j + 1);
	numIslands(grid, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
	row = grid.size();
	col = grid[0].size();

	int num_islands = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == '1')
			{
				numIslands(grid, i, j);
				num_islands++;
			}
		}
	}

	return num_islands;
}
