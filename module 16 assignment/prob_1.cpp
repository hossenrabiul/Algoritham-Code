#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int par[N];
bool trac[N];
int cnt = 0;
void dfs(int src)
{
    vis[src] = true;

    for (int child : v[src])
    {
        if (vis[child] && par[src] != child)
        {
            cnt++;
        }
        if (vis[child] == false)
        {
            par[child] = src;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(par,-1,sizeof(par));
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}