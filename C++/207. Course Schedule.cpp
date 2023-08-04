bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    vector<int> incoming(numCourses, 0); 
    vector<list<int>> graph(numCourses, list<int>()) ; 

    for(int i = 0 ; i < prerequisites.size() ; i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        incoming[prerequisites[i][0]]++ ; 
    }       

    queue<int> q; 
    for(int i = 0 ; i < numCourses ; i++)
    {
        if(incoming[i]==0)
            q.push(i); 
    }

    int u ; 
    while(!q.empty())
    {
        u = q.front();
        q.pop(); 

        for(int x : graph[u])
        {
            incoming[x]-- ; 
            if(incoming[x] == 0)
                q.push(x);
        }
    }

    for(int i = 0 ; i < numCourses ; i++)
    {
        if(incoming[i])
            return false ; 
    }

    return true ; 
}
