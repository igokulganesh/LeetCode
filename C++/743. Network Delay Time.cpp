typedef pair<int, int> pi ; 

int minDistance(vector<int>& dist, vector<bool>& isVisited)
{
    int d = INT_MAX ; 
    int res = -1 ;

    for(int i = 0 ; i < dist.size() ; i++)
    {
        if(isVisited[i] == false and d > dist[i])
        {
            d = dist[i] ; 
            res = i ;    
        }
    }
    return res ; 
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
    vector<list<pi>> graph(n, list<pi>()); 
    
    for(int i = 0 ; i < times.size() ; i++)
    {
        graph[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
    }

    vector<int> dist(n, INT_MAX); 
    dist[k-1] = 0 ; 

    vector<bool> isVisited(n, false); 
    int u, v, w ; 
    for(int i = 0 ; i < n-1 ; i++)
    {
        u = minDistance(dist, isVisited);
        isVisited[u] = true; 

        for(pi p : graph[u])
        {
            v = p.first ;  
            w = p.second ; 
            if(isVisited[v] == false and dist[u] != INT_MAX and dist[u] + w < dist[v] )
                dist[v] = w + dist[u] ; 
        }
    }

    int res = 0 ; 
    for(int i = 0 ; i < n ; i++)
    {
        if(dist[i] == INT_MAX)
            return -1 ; 
        res = max(res, dist[i]); 
    }

    return res ; 
}