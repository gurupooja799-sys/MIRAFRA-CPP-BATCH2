#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<utility>
#include<climits>
#include<list>
using namespace std;
vector<pair<pair<int,int>,int>> calculateMST(int n,vector<pair<pair<int,int>,int>>&g)
{
    int u,v,w;
    unordered_map<int,list<pair<int,int>>>adj;
    for(auto edge:g)
    {
        u=edge.first.first;
        v=edge.first.second;
        w=edge.second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>visited(n+1,false);
    vector<int>key(n+1,INT_MAX);
    vector<int>parent(n+1,-1);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[1]=0;
    pq.push({0,1});
    
    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();
        
        if(visited[u])
        continue;
        
        visited[u]=true;
        for(auto neighbour:adj[u])
        {
            int v=neighbour.first;
            int w=neighbour.second;
            if(!visited[v] && w < key[v])
            {
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
        
    }
    
    vector<pair<pair<int,int>,int>>result;
    for(int i=2;i<=n;i++)
    {
        result.push_back({{parent[i],i},key[i]});
    }
    
    return result;
}    

int main()
{
    int n = 5;

    vector<pair<pair<int,int>, int>> edges = {
        {{1,2}, 2},
        {{1,3}, 3},
        {{2,3}, 1},
        {{2,4}, 4},
        {{3,4}, 5},
        {{4,5}, 7}
    };

    auto mst = calculateMST(n, edges);
    int min_weight;

    cout << "Edges in MST:\n";
    for (auto edge : mst)
    {
        cout << edge.first.first << " - "
             << edge.first.second << "  weight: "
             << edge.second << endl;
             
             min_weight+=edge.second;
    }
    
    cout<<"\nminimum weight of spanning graph="<<min_weight<<endl;

    return 0;
}












    
    
    
    
    
    
    
    
