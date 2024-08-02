#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
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
    dsu_initialize(n);
    vector<Edge> vc;
    long long int Totalcost = 0;
    int ans = 0;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        vc.push_back(Edge(u, v, c));
    }
    sort(vc.begin(), vc.end(), cmp);
    for (Edge val : vc)
    {
        int leaderU = dsu_find(val.u);
        int leaderV = dsu_find(val.v);

        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union(val.u, val.v);
            Totalcost += val.c;
            ans++;
        }
    }

    if (ans == n - 1)
    {
        cout << Totalcost << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}