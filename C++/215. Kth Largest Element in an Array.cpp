// Just Sorting (Accepted)
int findKthLargest(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end()); 
    return nums[nums.size()-k] ; 
}

 
/* 
    [Using Max Heap] 
idea is as follow heapify the given array [n*logn]
Pop k-1 elements then return the top element

*/ 

int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int> pq ; 

    for(int i = 0 ; i < nums.size() ; i++)
    {
        pq.push(nums[i]);
    }    

    while(--k)
        pq.pop(); 

    return pq.top(); 
}



/*
    [Using Min Heap]

In this method add each element to the min heap
and check whether the size of heap is large then k 
then pop() the min heap
at the end return the top element from the heap 

*/

int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int, vector<int>, greater<int>> pq ;

    for(int i = 0 ; i < nums.size() ; i++)
    {
        pq.push(nums[i]) ; 

        if(pq.size() > k)
            pq.pop(); 
    } 

    return pq.top();
}


/*
    [Quick Sort Approach] 
Here we use quick sort partioning method to find the kth position 
Time Complexity : O(n) [Average Only] 

*/

int partition(vector<int> & nums, int low, int high)
{
    int i = low + 1 ; 
    int j = high ; 

    while(1)
    {
        while( i < high and nums[i] < nums[low])
            i++ ; 

        while( j > low and nums[low] < nums[j] )
            j-- ; 

        if(i >= j)
            break ; 
        swap(nums[i], nums[j]); 
    }
    swap(nums[low], nums[j]);

    return j ;  
}

int findKthLargest(vector<int>& nums, int k) 
{
    int low = 0, high = nums.size()-1 ; 
    k = high - k + 1 ; // we need to find this position from the sorted array [Note we don't sort entire array we just find the position of kth element in the sorted array]
    
    while(low < high)
    {
        int p = partition(nums, low, high); 

        if(p < k)
            low = p + 1 ; 
        else if( p > k)
            high = p - 1 ;
        else 
            break ;  
    }
    return nums[k]; 
}
