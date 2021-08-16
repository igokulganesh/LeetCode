vector<vector<int>> threeSum(vector<int>& nums) 
{
    if(nums.size() < 3) 
        return {{}}; 

    vector<vector<int>> res ; 
    sort(nums.begin(), nums.end()); 

    int target = 0, sum ; 
    int j, k ; 

    // i is start -> j = middle -> k = last 
    for(int i = 0 ; i < nums.size()-2 ; i++)
    {
        // if first number is already larger then target then target no longer exists 
        if(nums[i] > target)
            break ; 

        // skip the repeats  
        if(i > 0 and nums[i] == nums[i-1])
            continue ; 

        j = i+1 ; 
        k = nums.size()-1 ; 

        while( j < k )
        {
            sum = nums[i] + nums[j] + nums[k] ; 

            if(sum == target)
            {
                res.push_back({nums[i] , nums[j] , nums[k]}); 

                // to handle the duplicates 
                while( j < nums.size()-1 and nums[j] == nums[j+1])
                    j++ ;

                while( k > 0 and nums[k] == nums[k-1])
                    k-- ; 

                // Above while loops handle only duplicates
                j++ ; 
                k-- ; 
            }
            else if(sum > target)
                k-- ;
            else
                j++ ;
        }
    }
    return res ; 
}   