int maxSubArray(vector<int>& nums) 
{
    int cursum = 0 , i = 0, maxSum = nums[0] ; 
    
    for(int x : nums )
    {
        cursum += x ; 
        maxSum = max(cursum, maxSum);
        cursum = max(cursum, 0); 
    }

    return maxSum ; 
}
   