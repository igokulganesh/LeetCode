/*
    Two Pointers Technique 
    Time: O(n) linear
    Space: O(1) Constant
*/
bool isPalindrome(string s) 
{
    int i = 0, j = s.size()-1; 

    while(i < j)
    {
        while( i < j and !iswalnum(s[i]))
            i++ ; 

        if(i < j)
            s[i] = tolower(s[i]); 

        while(i < j and !iswalnum(s[j]))
            j-- ; 

        if(i < j)
            s[j] = tolower(s[j]);

        if(i < j and s[i] != s[j])
            return false ; 

        i++ ; 
        j-- ;
    }   

    return true ;  
}