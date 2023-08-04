vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end()); 
    return kSum(nums, target, 0, 4); 
}

vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k)
{
    vector<vector<int>> res ;
    if(start == nums.size() or static_cast<long>(nums[start]) * k > target or target > long(nums.back()*4))
        return res ;

    if(k == 2)
        return twoSum(nums, target, start); 

    for(int i = start ; i < nums.size(); i++)
    {
        if(i > start and nums[i] == nums[i-1]) // handle Duplicates 
            continue ; 

        for(vector<int>& subRes : kSum(nums, target-nums[i], i+1, k-1))
        {
            subRes.push_back(nums[i]);
            res.push_back(subRes);  
        }
    }

    return res ; 
}

vector<vector<int>> twoSum(vector<int>& nums, int target, int start)
{
    vector<vector<int>> res ;
    int i = start, j = nums.size()-1, sum ; 

    while( i < j )
    {
        sum = nums[i] + nums[j] ; 

        if(sum < target or (i > start and nums[i] == nums[i-1]))
            i++ ; 
        else if(sum > target or (j < nums.size()-1 and nums[j] == nums[j+1]))
            j-- ; 
        else
            res.push_back({nums[i++], nums[j--]}); 
    }

    return res ; 
}