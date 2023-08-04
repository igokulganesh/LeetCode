/*
    Seems easy one but isn't 
    there are many approaches to solve this problem but efficient one is linked list cycle detection 
*/

int findDuplicate(vector<int>& nums) 
{
    int slow = nums[0] ; 
    int fast = nums[0] ; 

    do
    {   
        slow = nums[slow];
        fast = nums[nums[fast]]; 
    }while(slow != fast); 

    slow = nums[0] ;
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast] ;
    }

    return fast ; 
}

 
// Using Hash (Inefficient space O(n)) accepted but doesn't meet the constraints 
int findDuplicate(vector<int>& v) 
{   
    vector<int> n(v.size()+1, 0) ; 

    for(int i = 0 ; i < v.size() ; i++)
    {
        if(n[v[i]])
            return v[i] ; 
        n[v[i]]++ ; 
    }
    return 0 ; 
}



