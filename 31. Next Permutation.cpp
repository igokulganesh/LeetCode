void nextPermutation(vector<int>& nums) 
{ 
    int i = nums.size()-1 ; 
    while(--i >= 0)
        if(nums[i] < nums[i+1])
            break ; 

    int j ; 
    if(i >= 0)
    {
        j = i+1 ;
        while(j < nums.size() and nums[i] < nums[j])
            j++ ;
        j-- ; 

        swap(nums[i], nums[j]);
    }

    j = nums.size()-1;
    i++; 
    while( i < j )
        swap(nums[i++], nums[j--]);
}

/*

3 2 1

1 5 8 4 7 6 5 3 1 // finding the decreasing point
1 5 8 5 7 6 4 3 1 // swap them with next greater 
1 5 8 5 1 3 4 6 7 // reverse the reamining 

*/