#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void BFStravesal(int start,int end,vector<vector<int>>&adj)
{
    int v=adj.size();
    vector<bool>visited(v,false);
    queue<int>q;
    q.push(start);
    visited[start]=true;
    vector<int>parent(v,-1);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int neighbour:adj[node])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                parent[neighbour]=node;
                visited[neighbour]=true;
          }
        }
    }
    vector<int>path;
    for(int i=end; i!=-1;i=parent[i])
    {
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    for(auto &x:path)
    cout<<x<<" ";
    
    cout<<"\nshotest path "<<path.size()-1<<endl;
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
    BFStravesal(0,4,adj);
    return 0;
}










