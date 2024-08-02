#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<int> vc[100005];
void dfs(int src)
{
    vis[src] = true;
    for (int val : vc[src])
    {
        if (vis[val] == false)
        {
            vis[val] = true;
            dfs(val);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    dfs(1);
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}