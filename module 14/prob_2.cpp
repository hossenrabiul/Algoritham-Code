#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> vc;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vc.push_back(Edge(u, v, w));
    }
    for (Edge ed : vc)
    {
        cout << ed.u << ed.v << ed.w;
    }
    return 0;
}