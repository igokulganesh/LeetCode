// 2-pass 
void sortColors(vector<int>& nums) 
{
    int w = 0, b = 0, n = nums.size() ;

    for(int x : nums)
    {
        if(x == 0)
            w++ ; 
        else if(x == 1) 
            b++ ;
    } 

    int i = 0 ; 
    while(i < w)
        nums[i++] = 0 ; 

    while(i < b)
        nums[i++] = 1 ; 

    while(i < n)
        nums[i++] = 2 ;  
}

// single pass with Binary search 
void sortColors(vector<int>& nums)
{
    int low = 0, high = nums.size()-1, mid = 0; 
    while(mid <= high)
    {
        if(nums[mid] == 0)
            swap(nums[mid++], nums[low++]); 
        else if(nums[mid] == 2)
            swap(nums[mid], nums[high--]); 
        else
            mid++ ;
    }
}