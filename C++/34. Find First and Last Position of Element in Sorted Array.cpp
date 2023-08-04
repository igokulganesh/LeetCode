int findStart(vector<int> & nums, int target)
{
    int low = 0, high = nums.size()-1, mid ;
    int res = -1 ; 

    while(low <= high)
    {
        mid = low + (high-low)/2 ; 

        if(nums[mid] >= target)
            high = mid-1 ; 
        else
            low = mid+1 ; 

        if(nums[mid]  == target)
            res = mid ; 
    }
    return res ; 
}

int findEnd(vector<int> & nums, int target)
{
    int low = 0, high = nums.size()-1, mid ;
    int res = -1 ; 

    while(low <= high)
    {
        mid = low + (high-low)/2 ; 

        if(nums[mid] <= target)
            low = mid+1 ; 
        else
            high = mid-1 ; 

        if(nums[mid]  == target)
            res = mid ; 
    }

    return res ; 
}

vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> res(2); 

    res[0] = findStart(nums, target);
    res[1] = findEnd(nums, target); 

    return res ;   
}