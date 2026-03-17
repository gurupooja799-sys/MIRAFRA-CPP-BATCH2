#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited)
{
    visited[node]=true;
    for(auto &neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            if(dfs(neighbour,node,adj,visited))
            return true;
        }
        else if(neighbour!=parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int V=4;
    vector<vector<int>>adj(V);
    vector<bool>visited(V,false);
    int flag=0;
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[2].push_back(3);
    adj[3].push_back(2);
    
    adj[3].push_back(0);
    adj[0].push_back(3);
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1,adj,visited))
            {
                flag=1;
                break;
            }
        }
    }
    
    if(flag)
    {
        cout<<"Cycle detected\n";
    }
    else
    {
        cout<<"Cycle not detected\n";
    }
    return 0;
}










