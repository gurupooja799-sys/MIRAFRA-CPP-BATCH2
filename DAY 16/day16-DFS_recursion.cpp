#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void DFStravesal(int node,vector<bool>&visited,vector<vector<int>>&adj)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            DFStravesal(neighbour,visited,adj);
        }
    }
}
int main()
{
    int v=5;
    vector<vector<int>>adj(v);
    vector<bool>visited(v,false);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};
    cout<<"DFS traversal\n";
    DFStravesal(0,visited,adj);
    return 0;
}










