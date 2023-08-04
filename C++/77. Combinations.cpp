#include <bits/stdc++.h>

using namespace std ; 

void combine(int n, int k, vector<int> & sub, vector<vector<int> > & ans, int i)
{
	if(sub.size() == k)
		ans.push_back(sub); 

	for(int j = i ; j <= n ; j++)
	{
		sub.push_back(j) ;

		combine(n, k, sub, ans, j+1); 

		sub.pop_back();  
	}
}

vector<vector<int>> combine(int n, int k) 
{
	vector<int> sub ;
	vector<vector<int> > ans ; 

	combine(n, k, sub, ans, 1); 

	return ans ; 
}

int main()
{
	int n , k ; 
	cin >> n  >> k ; 

	auto res = combine(n, k) ; 

	for(auto a : res)
	{
		for(auto b : a)
			cout << b << " " ; 
		cout << endl ; 
	}

	return 0 ; 
}