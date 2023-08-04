bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size(), n = matrix[0].size(); 

    int row = 0; 

    while(row < m)
    {
        if(matrix[row][n-1] >= target)
            break ; 
        row++ ; 
    }

    if(row < m)
    {
        int low = 0, high = n-1, mid ;
        while(low <= high)
        {
            mid = low + (high-low)/2 ; 

            if(matrix[row][mid] == target)
                return true ; 

            if(matrix[row][mid] > target)
                high = mid-1 ; 
            else
                low = mid+1 ; 
        }
    }

    return false ; 
}