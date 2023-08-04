int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
{
    vector<vector<int>> graph(n, vector<int>()); 
    
    for(int i = 0 ; i < n ; i++)
        if(manager[i] != -1)
            graph[manager[i]].push_back(i); 

    int minutes = 0, len, u, v ;
    queue<pair<int, int>> q ;
    q.push({headID, 0});

    while(!q.empty())
    {
        u = q.front().first ;
        v = q.front().second ;
        q.pop();
        minutes = max(minutes, v);

        for(int x : graph[u])
            q.push({x, v + informTime[u]});
    }
    return minutes ;
}