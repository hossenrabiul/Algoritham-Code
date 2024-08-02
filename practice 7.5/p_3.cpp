#include <bits/stdc++.h>
using namespace std;
class eage
{
public:
    int u, v, c;
    eage(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int dis[100];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<eage> Elist;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Elist.push_back(eage(u, v, c));
    }
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (eage ed : Elist)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << "3000"
                 << " ";
        }
        else
        {
            cout << dis[i] << " ";
        }
    }
    return 0;
}