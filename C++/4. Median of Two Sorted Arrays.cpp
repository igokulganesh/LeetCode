vector<int> merge(vector<int> & n1, vector<int> & n2)
{
	int i = 0, j = 0 ;
	vector<int> c ; 
	while(i < n1.size() and j < n2.size())
	{
		if(n1[i] < n2[j])
			c.push_back(n1[i++]) ;
		else
			c.push_back(n2[j++]) ;
	}

	while( i < n1.size() )
		c.push_back(n1[i++]) ;
	
	while( j < n2.size() )
		c.push_back(n2[j++]) ;

	return c ; 
}

double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) 
{
	n1 = merge(n1, n2) ; 

	int n = n1.size() ; 

	if(n%2) // odd size array 
	{
		return n1[(n-1)/2] ;
	}
	else
	{
		int a = n1[n/2] ; 
		int b = n1[(n/2)-1];
		return double(a+b)/2 ; 
	}
}

/* Time complexity for the above method is O(n) */