#include <bits/stdc++.h>

using namespace std ; 

int myAtoi(string & s) 
{
	long res = 0 ;
	bool positive = true ; 

	int i = 0 ; 
	int n = s.size() ; 

	// step 1 : remove leading white space 
	while(i < n and s[i] == ' ')
		i++ ; 

	// step 2: check + or - 

	if(i < n and s[i] == '-')
	{
		positive = false ;
		i++ ;
	}
	else if(i < n and s[i] == '+')
		i++ ; 

	// step 3 & 4: read and convert to interger 

	int c ; 
	while(i < n)
	{ 
		c = s[i] - '0' ; 
		if( 0 <= c and c <= 9 )
		{
			res = (res * 10) + c ; 

			if(res > INT_MAX)
				break ; 
		}
		else
			break ;
		i++ ; 
	}

	// step 5 & 6 : check for interger range 
	if(positive)
		return min(res, (long)INT_MAX) ; 
	return max(-res, (long)INT_MIN) ; 
}

int main()
{
	string s ;
	cin >> s ; 

	cout << myAtoi(s) ;
}