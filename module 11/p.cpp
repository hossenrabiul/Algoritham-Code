#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);

    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderA] = leaderB;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderB] = leaderA;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> vc;
    dsu_initialize(n);
    int totalCost = 0;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        vc.push_back(Edge(u, v, c));
    }
    sort(vc.begin(), vc.end(), cmp);

    for (Edge ed : vc)
    {
        int leaderA = find(ed.u);
        int leaderB = find(ed.v);
        if (leaderA == leaderB)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.c;
        }
    }

    cout << totalCost;
    return 0;
}