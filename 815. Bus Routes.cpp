#include <bits/stdc++.h>

using namespace std ;

int find(vector<vector<int>>& routes, int x)
{	
	for(int i = 0 ; i < routes.size() ; i++)
	{
		for(int j = 0 ; j < routes[i].size() ; j++)
		{
			if(routes[i][j] == x)
				return i ; 
		}
	}

	return -1 ; 
}

bool find(vector<vector<int>>& routes, int r1, int r2)
{
	for(int i = 0 ; i < routes[r1].size() ; i++)
	{
		for(int j = 0 ; j < routes[r2].size() ; j++)
		{
			if(routes[r1][i] == routes[r2][j])
				return true ; 
		}
	}

	return false ; 
}

int BFS(vector<vector<int>> &graph, int src, int des)
{
	vector<bool> isVisited(graph.size(), false) ; 
	queue<int> q ; 

	q.push(src) ; 
	isVisited[src] = true ; 
	int res = 1 ; 

	while(!q.empty())
	{
		int u = q.front() ; 
		q.pop() ; 

		for(int i = 0 ; i < graph.size() ; i++)
		{
			if(graph[u][i] and isVisited[i] == false)
			{
				isVisited[i] = true ; 
				q.push(i) ; 

				if(i == des) 
					return res ; 
			}
		}

		res++ ;
	}	
	return -1 ;
}

int numBusesToDestination(vector<vector<int>>& routes, int s, int t) 
{
	int src_idx = find(routes, s) ; 
	int des_idx = find(routes, t) ; 

	cout << src_idx << endl ; 
	cout << des_idx << endl ; 

	if(src_idx == -1 or des_idx == -1)
		return -1 ;

	vector<vector<int> > graph(routes.size(), vector<int>(routes.size(), 0)); 

	for(int i = 0 ; i < routes.size()-1; i++)
	{
		for(int j = i+1 ; j < routes.size() ; j++)
		{
			if(find(routes, i, j))
			{
				graph[i][j] = 1 ;
				graph[j][i] = 1 ;	
			}
		}
	}

	for(int i = 0 ; i < graph.size() ; i++)
	{	
		for(int j = 0 ; j < graph.size() ; j++)
			cout << graph[i][j] << " " ; 
		printf("\n");
	}

	return BFS(graph, src_idx, des_idx) ; 
}

int main()
{
	vector<vector<int>> routes = 
	{ 	{
			7, 12
		},
		{ 
			4, 5, 15
		},
		{
			6 
		},
		{
			15, 9
		},
		{
			9, 12, 13
		}
	} ; 

	int s = 15, t = 12 ; 
	cout << numBusesToDestination(routes, s, t) ; 
}