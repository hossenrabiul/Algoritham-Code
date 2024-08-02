#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
vector<int> vc;
bool vis[N];
int dis[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 1;

    while (!q.empty())
    {
        int pr = q.front();
        q.pop();
        vc.push_back(pr);
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
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int a, b;
    cin >> a >> b;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(a);
    cout << dis[b] << endl;
    for (int i = 0; i < dis[b] + 1; i++)
    {
        cout << vc[i] << " ";
    }

    return 0;
}