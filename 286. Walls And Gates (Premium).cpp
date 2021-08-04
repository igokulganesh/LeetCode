/*

Problem Statement 

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
 0 - A gate.
INF - Infinity means an empty room. 

We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

*/
const int INF = 2147483647 ;

void wallsAndGates(vector<vector<int>> &rooms) 
{
	queue<pair<int, int>> q ; 

	int r = rooms.size(), c = rooms[0].size() ;

	for(int i = 0 ; i < r ; i++ )
		for(int j = 0 ; j < c ; j++)
			if(rooms[i][j] == 0)
				q.push({i, j}) ; 

	int x, y ; 
	while(!q.empty())
	{
		x = q.front().first ; 
		y = q.front().second ; 
		q.pop(); 

		if(x+1 < r and rooms[x+1][y] == INF)
		{
			rooms[x+1][y] = rooms[x][y] + 1 ; 
			q.push({x+1, y}); 
		}
		
		if(x-1 >= 0 and rooms[x-1][y] == INF)
		{
			rooms[x-1][y] = rooms[x][y] + 1 ; 
			q.push({x-1, y}); 
		}
		
		if(y+1 < c and rooms[x][y+1] == INF)
		{
			rooms[x][y+1] = rooms[x][y] + 1 ; 
			q.push({x, y+1}); 
		}
		
		if(y-1 >= 0 and rooms[x][y-1] == INF)
		{
			rooms[x][y-1] = rooms[x][y] + 1 ; 
			q.push({x, y-1}); 
		}
	}
}

/*
tags:
Amazon
Google
*/