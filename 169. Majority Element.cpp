int majorityElement(vector<int> & v)
{        
    unordered_map<int, int> m ; 
    
    for(int i = 0 ; i < v.size() ; i++)
        m[v[i]]++ ; 

    int major = v[0] ; 
    int count = m[v[0]] ; 
    
    for(auto i : m)
    {
        if(count <= i.second)
        {
            count = i.second ;
            major = i.first ; 
        }
    }
    
    return major ; 
}

