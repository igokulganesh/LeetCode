vector<int> twoSum(vector<int>& nums, int target) 
{
    int i = 0, j = nums.size()-1 ; 

    while(i < j)
    {
        if(nums[i]+nums[j] == target)
            break ; 

        if(nums[i]+nums[j] < target)
            i++ ;
        else 
            j-- ; 
    }

    return {i+1, j+1};
}