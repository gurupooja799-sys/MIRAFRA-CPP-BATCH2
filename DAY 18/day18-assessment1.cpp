#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
#include<climits>
#include<utility>

using namespace std;
string nodes[]={"Engine_Control","Battery_Management","Dashboard","ADAS_Camera",
                "Rear_parking_sensor","Infotainment"};
vector<pair<pair<string,string>,int>>  minweightprims(int n,vector<pair<pair<string,string>,int>>&g)
{
    unordered_map<string,list<pair<string,int>>>adj;
    for(auto edge: g)
    {
        string u=edge.first.first;
        string v=edge.first.second;
        int w=edge.second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    unordered_map<string,bool>visited;
    unordered_map<string,int>key;
    unordered_map<string,string>parent;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
    for(int i=0;i<n;i++)
    {
        key[nodes[i]]=INT_MAX;
        
    }
    key[nodes[0]]=0;
    pq.push({0,nodes[0]});
    while(!pq.empty())
    {
        string u=pq.top().second;
        pq.pop();
        
        if(visited[u])
        continue;
        
        visited[u]=true;
        for(auto neighbour:adj[u])
        {
            auto v=neighbour.first;
            auto w=neighbour.second;
            if(!visited[v] && w < key[v])
            {
                key[v]=w;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    vector<pair<pair<string,string>,int>>result;
    for(int i=1;i<n;i++)
    {
        result.push_back({{parent[nodes[i]],nodes[i]},key[nodes[i]]});
    }
    
    return result;
    
    
}
int main()
{
    int n=6;
    vector<pair<pair<string,string>,int>>edge;
    edge.push_back({{"Engine_Control","Battery_Management"},3});
    edge.push_back({{"Engine_Control","Dashboard"},4});
    edge.push_back({{"Battery_Management","Dashboard"},2});
    edge.push_back({{"Battery_Management","ADAS_Camera"},6});
    edge.push_back({{"Dashboard","ADAS_Camera"},5});
    edge.push_back({{"Dashboard","Rear_parking_sensor"},7});
    edge.push_back({{"ADAS_Camera","Infotainment"},4});
    edge.push_back({{"Rear_parking_sensor","Infotainment"},3});
    
    auto mst = minweightprims(n, edge);
    int min_weight=0;

    cout << "Edges in MST:\n";
    for (auto edge : mst)
    {
        cout << edge.first.first << "  -> "
             << edge.first.second << "  weight: "
             << edge.second << endl;
             
             min_weight+=edge.second;
    }
    
    cout<<"\nminimum weight of spanning graph="<<min_weight<<endl;

    return 0;
}












