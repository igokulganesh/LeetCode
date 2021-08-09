void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size(), a, b, c, d ;

    for(int i = 0 ; i < n/2 ; i++)
    {
        for(int j = i ; j < n-i-1 ; j++)
        {
            a = matrix[i][j] ;
            b = matrix[j][n-i-1] ;
            c = matrix[n-i-1][n-j-1] ; 
            d = matrix[n-j-1][i] ; 

            matrix[i][j] = d ;
            matrix[j][n-i-1] = a ;
            matrix[n-i-1][n-j-1] = b ; 
            matrix[n-j-1][i] = c ; 
        }
    }    
}

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24 
30 31 32 33 24 
40 41 42 43 44