#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> v[N];
bool vis[N];
int dis_from_src[N];
int dis_from_des[N];
void bfs(int s, int trak)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    if (trak == 1)
    {
        dis_from_src[s] = 0;
    }
    else
    {
        dis_from_des[s] = 0;
    }
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                if (trak == 1)
                {
                    dis_from_src[child] = dis_from_src[par] + 1;
                }
                else
                {
                    dis_from_des[child] = dis_from_des[par] + 1;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
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
        int s, d;
        cin >> s >> d;

        memset(vis, false, sizeof(vis));

        memset(dis_from_src, -1, sizeof(dis_from_src));

        bfs(s, 1);
        memset(vis, false, sizeof(vis));

        memset(dis_from_des, -1, sizeof(dis_from_des));
        bfs(d, 2);

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int val = dis_from_src[i] + dis_from_des[i];
            ans = max(ans, val);
        }
        cout << "case " << cs++ << ": " << ans << endl;
        for (int i = 0; i < n; i++)
        {
            v[i].clear(); 
        }
    }
    return 0;
}