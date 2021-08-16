vector<int> majorityElement(vector<int>& nums) 
{
    unordered_map<int, int> m ; 
    
    for(int i = 0 ; i < nums.size() ; i++)
        m[nums[i]]++ ; 
    
    vector<int> ans ; 

    int n = nums.size()/3 ; 
    
    for(auto it : m )
    {
        if(it.second > n)
            ans.push_back(it.first) ; 
    }
    
    return ans ; 
}

/*
We should optimize the space complexity 
So slightly modify the Moore's voting Algorithm 
*/

vector<int> majorityElement(vector<int>& nums) 
{
    if(nums.size() <= 1)
        return nums ; 

    int count1 = 0, count2 = 0 ;
    int major1, major2 ; 

    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(nums[i] == major1)
            count1++ ;
        else if(nums[i] == major2)
            count2++ ; 
        else if(count1 == 0)
        {
            major1 = nums[i] ; 
            count1++ ; 
        }
        else if(count2 == 0)
        {
            major2 = nums[i] ; 
            count2++ ; 
        }
        else
        {
            count1-- ; 
            count2-- ; 
        }
    }

    count1 = 0, count2 = 0 ; 
    for(int x : nums)
    {
        if(x == major1)
            count1++ ; 
        else if(x == major2)
            count2++ ; 
    }

    vector<int> res ; 

    if(count1 > nums.size()/3)
        res.push_back(major1); 

    if(count2 > nums.size()/3)
        res.push_back(major2); 

    return res ; 
}

1/3 = 0 
2/3 = 0 
3/3 = 1
4/3 = 1
5/3 = 1
6/3 = 2
7/3 = 2
8/3 = 2
9/3 = 3