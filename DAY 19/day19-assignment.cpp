#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum control_stations
{
    Traffic_Control,Power_Grid,Water_Supply,Hospital_Network,Police_Control,Data_Center
};
string nodes[]={"Traffic_Control","Power_Grid","Water_Supply","Hospital_Network",
                 "Police_Control","Data_Center"};
struct Edge {
    int u;     // source
    int v;     // destination
    int wt;    // weight
};

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with Path Compression
int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(u == v)
        return;

    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(const Edge &a, const Edge &b)
{
    return a.wt < b.wt;  // sort by weight
}

int minimumSpanningTree(vector<Edge> &edges, int n)
{
    // 1.Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    int minWeight = 0;
    int edgeCount = 0;

    cout << "Edges in MST:\n";

    // Step 2: Process edges
    for(const Edge &e : edges)
    {
        int u = e.u;
        int v = e.v;
        int wt = e.wt;

        if(findParent(parent, u) != findParent(parent, v))
        {
            unionSet(u, v, parent, rank);

            cout << nodes[u] << " - " << nodes[v] << " : " << wt << endl;

            minWeight += wt;
            edgeCount++;

            // Early stopping condition
            if(edgeCount == n - 1)
                break;
        }
    }

    return minWeight;
}

int main()
{
    int n = 6; // vertices 0 to 5

    vector<Edge> edges = { // u,v,w
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {2, 3, 3},
        {2, 5, 2},
        {2, 4, 4},
        {3, 4, 3},
        {5, 4, 3}
    };

    int totalWeight = minimumSpanningTree(edges, n);

    cout << "\nTotal MST Weight: " << totalWeight << endl;

    return 0;
}