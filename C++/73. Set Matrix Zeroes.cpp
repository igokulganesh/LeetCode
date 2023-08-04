void setZeroes(vector<vector<int>>& matrix) 
{
    int row = matrix.size() ;
    int col = matrix[0].size() ; 

    bool rowFlag = false, colFlag = false ; 

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0 ; 
                matrix[i][0] = 0 ; 

                if(i == 0) rowFlag = true ; 
                if(j == 0) colFlag = true ;
            } 
        }
    }

    for(int i = 1 ; i < row ; i++)
    {
        for(int j = 1 ; j < col ; j++)
        {
            if(matrix[0][j] == 0 or matrix[i][0] == 0)
                matrix[i][j] = 0 ; 
        }
    }

    if(rowFlag)
    {
        for(int i = 0 ; i < col ; i++)
            matrix[0][i] = 0 ;
    }


    if(colFlag)
    {
        for(int i = 0 ; i < row ; i++)
            matrix[i][0] = 0 ;
    }
}