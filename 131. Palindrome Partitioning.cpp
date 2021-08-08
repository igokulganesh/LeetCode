bool isPalindrome(string & s)
{
    int l = 0, h = s.size() -1 ; 

    while(l < h)
    {
        if(s[l] != s[h])
            return false ; 
        l++ , h-- ; 
    }
    return true ; 
}

void partition(string s, vector<string> & cur, vector<vector<string>> & res)
{
    if(s.empty())
    {
        res.push_back(cur); 
        return ; 
    }

    for(int i = 1 ; i <= s.size() ; i++)
    {
        string left(s.begin(), s.begin()+i); 
        string right(s.begin()+i, s.end());

        if(isPalindrome(left))
        {
            cur.push_back(left);
            partition(right, cur, res); 
            cur.pop_back(); // Backtracking
        }
    }
}

vector<vector<string>> partition(string s) 
{
    vector<vector<string>> res ;
    vector<string> cur ; 
    partition(s, cur, res); 
    return res ; 
}