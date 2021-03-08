#include <bits/stdc++.h>

using namespace std ; 

void subsets(vector<int> & v, vector<int> & sub, vector<vector<int> > & ans, int i)
{
	ans.push_back(sub); 

	for(int j = i ; j < v.size() ; j++)
	{
		sub.push_back(v[j]) ;

		subsets(v, sub, ans, j+1); 

		sub.pop_back();  
	}
}

vector<vector<int> > subsets(vector<int>& v) 
{
	vector<int> sub ;
	vector<vector<int> > ans ; 

	subsets(v, sub, ans, 0); 

	return ans ; 
}

int main()
{
	int n ; 
	cin >> n ; 
	vector<int> v(n) ; 

	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i] ; 
	}

	auto res = subsets(v) ; 

	for(auto a : res)
	{
		for(auto b : a)
			cout << b << " " ; 
		cout << endl ; 
	}

	return 0 ; 
}