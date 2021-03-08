int hackerlandRadioTransmitters(vector<int> v, int k) 
{
	int i = 0, c = 0 ; 

	int data ; 

	sort(v.begin(), v.end()); 

	while( i < v.size())
	{
		c++ ; 
		data = v[i] + k ; 
		while(i < v.size() and v[i] <= data )
			i++ ; 

		i--; 

		data = v[i] + k ; 

		while( i < v.size() and v[i] <= data)
			i++ ; 
	}

	return c ; 
}

TreeNode* recoverFromPreorder(string & s) 
{
	unordered_map<int, TreeNode*> m ; 
	int c = 0 ; 
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '-')
			c++ ;
		else
		{
			string n = "" ; 

			while( i < s.size() and s[i] != '-')
				n += s[i++] ; 
			i-- ; 
			m[c] = new TreeNode(stoi(n));

			if(c)
			{
				if(m[c-1]->left)
					m[c-1]->right = m[c] ; 
				else
					m[c-1]->left = m[c] ;
			}
			c = 0 ;  
		}
	}

	return m[0] ; 
}

void check(int n, int r, int c, set<pair<int, int> > &s, int &ans)
{
	pair<int, int> p ; 
	for(int i = r+1, j = c-1 ; i <= n and j >= 1 ; i++, j--)
	{
		p = make_pair(i, j) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}

	for(int i = r+1, j = c+1 ; i <= n and j <= n ; i++, j++)
	{
		p = make_pair(i, j) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}

	for(int i = r-1, j = c-1 ; i >= 1 and j >= 1 ; i--, j--)
	{
		p = make_pair(i, j) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}
	
	for(int i = r-1, j = c+1 ; i >= 1 and j <= n ; i--, j++)
	{
		p = make_pair(i, j) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}

	for(int i = c-1 ; i >= 1 ; i--)
	{
		p = make_pair(r, i) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}

	for(int i = c+1 ; i <= n ; i++)
	{
		p = make_pair(r, i) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}

	for(int i = r+1 ; i <= n ; i++)
	{
		p = make_pair(i, c) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}

	for(int i = r-1 ; i >= 1 ; i--)
	{
		p = make_pair(i, c) ; 
		if(s.find(p) == s.end())
			ans++ ; 
		else 
			break ; 
	}
}

int queensAttack(int n, int k, int r, int c, vector<vector<int> >& obstacles) 
{
	unordered_set<pair<int, int> > s ; 

	for(int i = 0 ; i < obstacles.size() ; i++)
	{
		pair<int, int> p = make_pair(obstacles[i][0], obstacles[i][1]) ; 
		s.insert(p);
	}

	int ans = 0 ; 

	check(n, r, c, s, ans);

	return ans ; 
}

int minimumLoss(vector<long> price) 
{
    long ans = INT_MAX; 

    for(int i = 0 ; i < price.size() ; i++)
    {
    	for(int j = i+1 ; j < price.size() ; j++)
    	{
    		if(price[i]-price[j] >= 0)
    		{
    			ans = min(ans, price[i]-price[j]) ; 
    		}

    	}
    }
    return ans ; 

}

int maxProfit(vector<int>& p)
{
	int ans = 0 ; 
	for(int i = 0 ; i < p.size() ; i++)
	{
		for(int j = i+1 ; j < p.size() ; j++)
		{
			if(p[i] < p[j])
				ans = max(p[i]-p[j], ans); 
		}
	}

	return ans ; 
}

int maxProfit( vector<int> & P )
{
	int ans = 0 , cur = 0 ; 
	for(int i = 1 ; i < p.size() ; i++)
	{
		if(p[cur] < p[i])
			ans = max(p[i]-p[cur], ans); 
		else
			cur = i ; 
	}

	return ans ; 
}

vector<vector<int> > generate(int numRows) 
{
 	vector<vector<int>> v; 

	for(int i = 0 ; i < numRows ; i++)
	{
		vector<int> t ; 
		for(int j = 0 ; j <= i ; j++ )
		{
			if( j == 0 or j == i)
				t.push_back(1); 
			else
			{
				int a = v.back()[j] + v.back()[j-1] ;
				t.push_back(a); 
			}

		}
		v.push_back(t) ; 
	}

	return v ; 
}

int maxSubArray(vector<int>& v) 
{
	int max_so_far = v[0] ; 
	int ans = v[0] ;  

	for(int i = 1 ; i < v.size() ; i++)
	{
		if(v[i] < max_so_far+v[i])
			max_so_far += v[i] ; 
		else 
			max_so_far = v[i] ; 

		ans = max(max_so_far, ans) ;  
	}

	return ans ; 
}

int maxSubarray(vector<int> & v)
{
	int maximum = v[0], ans = v[0] ;

	for(int i = 1 ; i < v.size() ; i++)
	{
		if(v[i] < maximum+v[i])
			maximum += v[i] ; 
		else 
			maximum = v[i] ; 

		ans = max(maximum, ans) ;  
	} 
	return ans ; 
}


int maxSubSeq(vector<int> & v)
{
	int sum = 0, m = INT_MIN ;  
	for(int i = 0 ; i < v.size() ; i++)
	{
 		if(v[i] > 0)
 			sum += v[i] ; 
 		m = max(m, v[i]) ;
	}

	return max(sum, m) ; 
}

vector<int> maxSubarray(vector<int> & arr) 
{
	vector<int> res(2, 0); 
	res[0] = maxSubarray(arr) ;
	res[1] = maxSubSeq(arr) ; 
	return res ; 
}

int trap(vector<int>& height)
{
	int res = 0 ; 
	int l = 0, r = height.size()-1 ; 
	int lm = 0, rm = 0 ; 

	while( l < r)
	{
		if(height[l] <= height[r])
		{
			if(height[l] > lm)
				lm = height[l] ; 
			else
				res += lm - height[l] ; 
			l++ ; 
		}
		else
		{
			if(height[r] > rm)
				rm = height[r] ; 
			else
				res += rm - height[r] ; 
			r-- ; 
		}
	}

	return res ; 
}

int pylons(int k, vector<int> arr) 
{
	int n = arr.size() ;
	int next = -1, prev = -1;
	int c = 0 ;  

	while( next < n-1 ) 
	{
		int on = min(next+k, n-1) ; 

		while(prev < on)
		{
			if(arr[on] == 1)
				break ; 
			on-- ; 
		}

		if(on == prev)
			return -1 ; 

		c++ ; 

		prev = on ; 
		next = on + k-1 ; 
	}

	return c ; 
}