#include<bits/stdc++.h>

using namespace std ; 

bool carPooling(vector<vector<int>>& trips, int capacity) 
{
	vector<int> v ; 

	vector<pair<int, int> > p ; 

	unordered_map<int, int> m ; 

	for(int i = 0 ; i < trips.size() ; i++)
	{
		m[trips[i][1]] += -trips[i][0] ; 
		m[trips[i][2]] +=  trips[i][0] ; 
	} 

	for(auto itr : m)
	{
		p.push_back(itr); 
	}

	sort(p.begin(), p.end()) ; 

	int n = capacity ; 

	for(int i = 0 ; i < p.size() ; i++)
	{
		if(n + p[i].second < 0 )
			return false ; 
		n += p[i].second ; 
	}

	return (n == capacity) ; 
}

int main() 
{
	int cap ; 

	vector<vector<int> > trips ; 

	cout << carPooling(trips, cap) ; 
}


