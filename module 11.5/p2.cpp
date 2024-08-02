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
        return node;
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
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> v;
    dsu_initilizer(n);
    int TotalCost = 0;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Edge(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    for (Edge ed : v)
    {
        int leaderA = dsu_find(ed.a);
        int leaderB = dsu_find(ed.b);

        if (leaderA == leaderB)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.a, ed.b);
            TotalCost = TotalCost + ed.c;
        }
    }

    cout << TotalCost << endl;
    return 0;
}