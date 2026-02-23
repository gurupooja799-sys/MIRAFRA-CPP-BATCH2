#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

enum cities
{
    gachibowli,hitechcity,ameerpet,madhapur,kothaguda
};
string nodes[]={"gachibowli","hitechcity","ameerpet","madhapur","kothaguda"};
class WeightedGraph
{
int V;
vector<vector<pair<int,int>>> adj;


public:
WeightedGraph(int vertices) {
V =vertices;
adj.resize(V);
    }

void addEdge(int u,int v,int weight)
{
adj[u].push_back({v,weight});
adj[v].push_back({u,weight});// remove if directed
}

void shortestPath(int src) 
{
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //pq minheap
//PQ -> {distance,node} // priority_queue<int> pq; bedefault vector
//priority_queue<T, c, comp> pq;  T is the data type , c is the underlying container, comp =minheap
vector<int>dist(V,INT_MAX); // INF INF INF INF INF 

dist[src] =0;  // 0 INF INF INF INF 
pq.push({0,src}); // 0 0

while(!pq.empty()) // 1 elmnt
{
int d =pq.top().first; // {distance,node}
int node =pq.top().second;
pq.pop();

for(auto edge :adj[node]) // adj[0] ={ 1,4} ,{2,1}  AdJ List ->{neighbor,weight}
{
int neighbor =edge.first; // 1 {neighbor,weight}
int weight =edge.second;  // 4

if(dist[neighbor]>d+weight) // dist[1]>0+4 ,INF >4
{
dist[neighbor] =d+weight; //  dist[1] =0+4
pq.push({ dist[neighbor],neighbor}); //  dist[1],neighbor})
                } // PQ -> {distance,node}
            }
        }

cout<<"Shortest distances from source "<<nodes[src]<<":\n";
for(int i =0;i<V;i++)
cout<<"To "<<nodes[i]<<" = "<<dist[i]<<endl;
    }
};

int main() {
WeightedGraph g(5);

g.addEdge(gachibowli,hitechcity,6); 
g.addEdge(gachibowli,ameerpet,15); 
g.addEdge(ameerpet,hitechcity,12); 
g.addEdge(hitechcity,madhapur,3);
g.addEdge(ameerpet,madhapur,7);
g.addEdge(madhapur,kothaguda,3);

g.shortestPath(ameerpet);//src=ameerpet

return 0;
}