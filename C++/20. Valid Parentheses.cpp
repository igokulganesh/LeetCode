bool isOpen(char ch)
{
    return (ch == '[' or ch == '{' or ch == '(') ; 
}

bool isMatch(char open, char close)
{
    switch(open)
    {
        case '{' : 
            return (close == '}') ; 
        case '[' :
            return (close == ']') ;
        case '(' : 
            return (close == ')') ; 
    }
    return false ;
}

bool isValid(string s) 
{
    stack<char> st ; 

    for(int i = 0 ; i < s.size(); i++)
    { 
        if(isOpen(s[i]))
            st.push(s[i]); 
        else if(!st.empty() and isMatch(st.top(), s[i]))
            st.pop(); 
        else
            return false ; 
    }    

    return st.empty(); 
}