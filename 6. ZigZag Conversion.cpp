string convert(string s, int numRows) 
{
	if(numRows == 1)
		return s ; 

	int n = s.size() ; 

	vector<string> v(min(n, numRows), "");

	bool isDown = false ;
	int cur = 0 ; 

	for(int i = 0 ; i < n; i++)
	{
		v[cur] += s[i] ;  

		if(cur == 0 or cur == numRows-1)
			isDown = !isDown ; 

		cur += (isDown ? 1 : -1) ; 
	} 

	string res = "" ; 

	for(int i = 0 ; i < v.size() ; i++)
		res += v[i] ;

	return res ; 
}