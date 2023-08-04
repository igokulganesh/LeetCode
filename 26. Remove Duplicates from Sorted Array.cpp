#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	int dup = nums[0], replace_index = 1;

	for(int i = 1; i < nums.size(); i++)
	{
		if(dup != nums[i])
		{
			dup = nums[i];
			nums[replace_index++] = nums[i];
		}
	}
	return replace_index-1; 
}

// best solution
int removeDuplicates(vector<int>& nums) 
{
    if(nums.size() <= 1)
        return nums.size() ; 
    
    int k = 1 ; 
    for(int i = 1 ; i < nums.size() ; i++)
    {
        if(nums[i-1] == nums[i])
            continue ; 

        nums[k++] = nums[i] ; 
    }

    return k ; 
}