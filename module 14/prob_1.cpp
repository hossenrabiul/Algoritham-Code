#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
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

        for (int child : v[pr])
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
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int src, d, k;
    cin >> src >> d >> k;
    bfs(src);
    if (dis[d] != -1 && dis[d] <= k * 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}