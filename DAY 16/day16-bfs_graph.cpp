#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFStravesal(int start,vector<vector<int>>&adj)
{
    int v=adj.size();
    vector<bool>visited(v,false);
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int x:adj[node])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
int main()
{
    int v=5;
    vector<vector<int>>adj(v);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};
    cout<<"BFS traversal\n";
    BFStravesal(0,adj);
    return 0;
}










