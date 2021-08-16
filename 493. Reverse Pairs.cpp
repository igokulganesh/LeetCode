/*
    Naive Approach
    Time limit exceeds 
    time: O(n^2)
*/

int reversePairs(vector<int>& nums) 
{
    int count = 0 ; 

    for(int i = 0 ; i < nums.size()-1 ; i++)
    { 
        for(int j = i+1 ; j < nums.size() ; j++)
        {
             if(nums[i] > long(2 * long(nums[j])))
                count++ ; 
        }
    }

    return count ;     
}

/*
    Merge Sort Approach
    Time: O(n log n)
*/
void merge(vector<int> & nums, int start, int mid, int end)
{
    vector<int> temp(end-start+1); 

    int i = start, j = mid+1, k = 0 ;

    while(i <= mid and j <= end)
    {
        if(nums[i] < nums[j])
            temp[k++] = nums[i++] ; 
        else
            temp[k++] = nums[j++] ; 
    }

    while( i <= mid)
        temp[k++] = nums[i++] ; 

    while( j <= end)
        temp[k++] = nums[j++] ; 

    k = 0, i = start ; 
    while( i <= end )
        nums[i++] = temp[k++] ; 
}

int mergePairs(vector<int> & nums, int start, int end)
{
    if(start >= end)
        return 0 ; 

    int mid = start + (end - start) / 2 ; 
    int res = mergePairs(nums, start, mid) + mergePairs(nums, mid+1, end);

    int i = start, j = mid+1 ;

    while(i <= mid and j <= end)
    {
        if(nums[i] > long(2 * long(nums[j])))
        {
            res += mid-i+1 ; 
            j++ ; 
        }
        else
            i++ ;
    }

    merge(nums, start, mid, end); 

    return res ; 
}

int reversePairs(vector<int> & nums)
{
    return mergePairs(nums, 0, nums.size()-1); 
}