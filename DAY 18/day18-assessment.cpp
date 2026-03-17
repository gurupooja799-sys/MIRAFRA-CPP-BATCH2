#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<climits>
using namespace std;
class Network
{
    int V;
    vector<vector<pair<int,int>>>router;
    
    public:
    Network(int vertices):V(vertices){
        router.resize(V);
    };
    
    void addEdge(int u,int v,int delay)
    {
        router[u].push_back({v,delay});
        router[v].push_back({u,delay});
    }
    
    void shortestpath(int start)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(V,INT_MAX);
        distance[start]=0;  //distance array
        pq.push({0,start});
        while(!pq.empty())
        {
            auto node=pq.top();
            int d=node.first;  
            int v=node.second;
            pq.pop();
            
            for(auto x:router[v])
            {
                
                int nver=x.first;    //neighbour node
                int ndis=x.second;  //neighbour node distance
                
                if(distance[nver] > (d+ndis))  //if previous distance > current distance sum
                {                              //assign new distance in distancevector
                    distance[nver]=d+ndis;
                    pq.push({distance[nver],nver});
                }
            }
        }
        
        for(int i=0;i<V;i++)
        {
            cout<<"router "<<i<<"->"<<distance[i]<<" milliseconds transmission delay\n";
        }
    }
};
int main()
{
    Network ntw(6);
    ntw.addEdge(0,1,3); //router1,router2,delay
    ntw.addEdge(0,2,2);
    ntw.addEdge(1,2,1);
    ntw.addEdge(1,3,5);
    ntw.addEdge(2,3,8);
    ntw.addEdge(2,4,10);
    ntw.addEdge(3,5,6);
    ntw.addEdge(4,5,2);
    
    
    ntw.shortestpath(0);
}















