#include <bits/stdc++.h>

using namespace std ; 

void permute(vector<int> & v, vector<vector<int> > & ans, int l, int h)
{

	if(l == h)
	{
		ans.push_back(v); 
		return ; 
	}

	for(int i = l ; i <= h ; i++)
	{
		swap(v[i], v[l]) ;

		permute(v, ans, l+1, h); 

		swap(v[i], v[l]) ;
	}
}

vector<vector<int>> permute(vector<int>& v) 
{	
	vector<vector<int> > ans ; 

	permute(v, ans, 0, v.size()-1); 

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

	auto res = permute(v) ; 

	for(auto a : res)
	{
		for(auto b : a)
			cout << b << " " ; 
		cout << endl ; 
	}

	return 0 ; 
}