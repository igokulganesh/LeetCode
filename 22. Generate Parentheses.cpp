bool isValid(string & p)
{
    stack<char> st ; 

    for(int i = 0 ; i < p.size() ; i++)
    {
        if(p[i] == '(')
            st.push(p[i]); 
        else if(st.empty())
            return false ; 
        else 
            st.pop() ; 
    }

    return st.empty(); 
}


void perumutate(string & p, int l, int h, vector<string> & res)
{
    if(l == h)
    {
        if(isValid(p))
            res.push_back(p); 
        return ; 
    }

    for(int i = l ; i <= h ; i++)
    {
        swap(p[i], p[l]); 
        perumutate(p, l+1, h, res);
        swap(p[i], p[l]);    
    }
}

vector<string> generateParenthesis(int n) 
{
    string p = "" ; 

    for(int i = 0 ; i < n ; i++)
        p += "()" ;

    vector<string> res ; 

    perumutate(p, 0, p.size()-1, res); 

    return res ;  
}

