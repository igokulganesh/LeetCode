//Brutte Fore method 
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> res , nums1 = nums ;

    int n = nums.size() ;
    int sum;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            sum = nums[i] + nums[j] ;
            if(sum == target)
            {
                res.push_back(i) ; 
                res.push_back(j) ;
                break ;
            }
        }
    }
    return res ;
}

// Using Extra space to optimize the time complexity
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> m ; // key : number ; value : index 

    for(int i = 0 ; i < nums.size() ; i++)
        m[nums[i]] = i ; 

    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(m.find(target-nums[i]) != m.end() and m[target-nums[i]] != i )
            return {i, m[target-nums[i]]} ; 
    }
    return {0}; 
}


// changing the given array leads to wrong answer
vector<int> twoSum(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end()); 
    int i = 0, j = nums.size()-1, sum ; 

    while(1)
    {
        sum = nums[i] + nums[j] ; 
        
        if(sum == target)
            return {i, j};

        if(sum > target)
            j-- ;
        else
            i++ ; 
    }
    return {0} ;
}