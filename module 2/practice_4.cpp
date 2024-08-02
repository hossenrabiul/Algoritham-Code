#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void dfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << par << " ";
        for (int i = 0; i < v[par].size(); i++)
        {
            int child = v[par][i];
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
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
    int src, des;
    cin >> src >> des;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    dfs(src);
    int x = des;
    vector<int> vc;
    while (x != -1)
    {
        vc.push_back(x);
        x = parent[x];
    }
    reverse(vc.begin(), vc.end());
    for (int a : vc)
    {
        cout << a << " ";
    }
    return 0;
}