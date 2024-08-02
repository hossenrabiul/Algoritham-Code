#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
int par[1005];
void dfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        // cout << pr << endl;
        for (int i = 0; i < v[pr].size(); i++)
        {
            int child = v[pr][i];
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[pr] + 1;
                par[child] = pr;
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
    memset(par, -1, sizeof(par));
    dfs(src);
    int x = des;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    
    for (int i : path)
    {
        cout << i << " ";
        
    }

    return 0;
}