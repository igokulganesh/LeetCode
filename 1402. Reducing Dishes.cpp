#include<bits/stdc++.h>

using namespace std ; 

int maxSatisfaction(vector<int>& s) 
{
    sort(s.begin(), s.end()) ; 

    int res = 0, temp ; 
    for(int i = 0 ; i < s.size() ; i++)
    {
    	temp = 0 ;
    	for(int j = i, k = 1 ; j < s.size() ; j++, k++)
    	{
    		temp += (s[j] * k) ; 
    	}
    	res = max(res, temp) ; 
    }
    return res ; 
}

int main()
{
	int n ; 
	cin >> n ; 
	vector<int> v(n) ; 

	for(int i = 0 ; i < n ; i++)
		cin >> v[i] ; 

	cout << maxSatisfaction(v) ; 

	return 0 ; 
}