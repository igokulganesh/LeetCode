#include <bits/stdc++.h>

using namespace std ; 

int m, n ; 

bool checkZero(vector<vector<int>>& mat)
{
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < n ; j++)
			if(mat[i][j])
				return false ;
	return true ; 
}

void doFlips(vector<vector<int>>& mat, int i, int j)
{
	mat[i][j] = !mat[i][j] ; 
	
	if(i-1 >= 0)
		mat[i-1][j] = !mat[i-1][j] ; 

	if(i+1 < m)
		mat[i+1][j] = !mat[i+1][j] ; 

	if(j-1 >= 0)
		mat[i][j-1] = !mat[i][j-1] ; 

	if(j+1 < n)
		mat[i][j+1] = !mat[i][j+1] ;
}

int minFlips(vector<vector<int>>& mat, int i, int j)
{
	if( i == m)
	{
		j++ ;
		i = 0 ; 
	}

	if(j == n)
		return (checkZero(mat) ? 0 : 99999) ; 
  

	int	res = minFlips(mat, i+1, j);
	doFlips(mat, i, j); 

	res = min(res, minFlips(mat, i+1, j) + 1 );
	doFlips(mat, i, j);

	return res ;
}

int minFlips(vector<vector<int>>& mat) 
{
	m = mat.size() ; 
	n = mat[0].size(); 
	int ans = minFlips(mat, 0, 0) ; 
	return ( ans >= 99999 ? -1 : ans )  ;
}

int main()
{
	vector<vector<int>> mat = {
		{1,1,1},
		{1,0,1},
		{0,0,0}
	};

	cout << minFlips(mat); 
}