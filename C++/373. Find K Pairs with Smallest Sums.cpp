vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
{
    vector<vector<int>> res ; 

    int i = 0, j = 0 ; 

    while(k-- > 0)
    {
        res.push_back({nums1[i], nums2[j]}); 

        if(nums1[i] < nums2[j])
            j++ ;
        else
            i++ ;  
    }

    return res ; 
}