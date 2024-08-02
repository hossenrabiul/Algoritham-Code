#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
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
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    memset(level,-1,sizeof(level));
    dfs(src);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " <<  level[i] << endl;
    }
    return 0;
}