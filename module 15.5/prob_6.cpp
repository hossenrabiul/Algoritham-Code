#include <bits/stdc++.h>
using namespace std;
vector<int> v[55];
bool vis[55];
int par[55];
bool ans = true;
void dfs(int src)
{
    vis[src] = true;

    for (int val : v[src])
    {
        if (vis[val] && val != par[src])
        {
            ans = false;
        }
        if (!vis[val])
        {
            par[val] = src;
            dfs(val);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }

    if (ans)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}