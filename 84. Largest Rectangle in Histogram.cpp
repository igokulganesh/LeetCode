
//	Time Limit Exceeded

int getHeight(vector<int> & h, int x)
{
	int c = 1 ;  

	for(int i = x+1 ; i < h.size() and h[x] <= h[i] ; i++)
		c++ ;  

	for(int i = x-1 ; i >= 0 and h[x] <= h[i] ; i++)
		c++ ;  

	return c * h[x] ; 
}

int largestRectangleArea(vector<int>& heights) 
{
	int res = 0 ; 

	for(int i = 0 ; i < heights.size() ; i++)
	{
		res = max(res, getHeight(heights, i)) ; 
	}
	
	return res ; 	    
}

int largestRectangleArea(vector<int> & h)
{
	int n = h.size() ; 

	int l[n], r[n] ;

	stack<int> s ; 

	for(int i = 0 ; i < n ; i++)
	{
		while(s.size() and h[i] <= h[s.top()] ) // we try to find boundry (which is small then current)  
			s.pop() ; 

		l[i] = (s.empty() ? 0 : s.top()+1) ; 
		s.push(i) ; 
	}

	while(s.size())
		s.pop();

	for(int i = n-1 ; i >= 0 ; i--)
	{
		while(s.size() and h[i] <= h[s.top()]) //  check for boundry ->
			s.pop() ; 

		r[i] = (s.empty() ? n-1 : s.top()-1) ;
		s.push(i) ; 
	}

	int res = 0 ; 

	for(int i = 0 ; i < n ; i++)
		res = max(res, (r[i]-l[i]+1)*h[i]) ; 
	

	return res ; 
}