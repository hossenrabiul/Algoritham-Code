#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int path[N];
int dis[N];
void bfs(int s)
{
    queue<int> pq;
    pq.push(s);
    vis[s] = true;
    dis[s] = 1;
    while (!pq.empty())
    {
        int par = pq.front();
        pq.pop();

        for (int child : v[par])
        {
            if (vis[child] == false)
            {

                pq.push(child);
                vis[child] = true;
                path[child] = par;
                dis[child] = dis[par] + 1;
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
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(path, -1, sizeof(path));
    bfs(1);
    vector<int> vc;
    if (dis[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << dis[n] << endl;
        int x = n;
        while (x != -1)
        {
            vc.push_back(x);
            x = path[x];
        }
    }
    reverse(vc.begin(), vc.end());
    for (int val : vc)
    {
        cout << val << " ";
    }
    return 0;
}