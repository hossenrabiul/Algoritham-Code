#include <bits/stdc++.h>
using namespace std;
vector<int> v[2000];
bool vis[1005];
void dfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        cout << pr << endl;
        // for (int i = 0; i < v[pr].size(); i++)
        // {
        //     int child = v[pr][i];
        //     cout << child << " ";
        // }
        for (int child : v[pr])
        {
            // cout << child << " ";
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
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
    dfs(src);
    return 0;
}