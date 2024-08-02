#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> vc[N];
bool vis[N];
int dis[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while (!q.empty())
    {
        int pr = q.front();
        q.pop();

        for (int child : vc[pr])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[pr] + 1;
            }
        }
    }
}
int main()
{
    int n, x;
    cin >> n >> x;
    int ads[1005][1005];
    vector<pair<int, int>> v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ads[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ads[i][j] == 1 && i != j)
            {
                v.push_back({i, j});
            }
        }
    }
    for (pair<int, int> pr : v)
    {
        vc[pr.first].push_back(pr.second);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(x);

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}