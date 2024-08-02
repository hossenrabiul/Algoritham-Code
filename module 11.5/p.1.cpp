#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initilizer(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> vc;
    dsu_initilizer(n);
    bool cycle = false;
    int TotalCost = 0;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vc.push_back(Edge(u, v, w));
    }
    sort(vc.begin(), vc.end(), cmp);
    for (Edge ed : vc)
    {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);
        if (leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            TotalCost += ed.w;
        }
    }

    cout << TotalCost;
    return 0;
}