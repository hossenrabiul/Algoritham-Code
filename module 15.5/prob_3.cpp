#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m;
vector<int> v[N];
bool vis[N];
int des[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    des[src] = 1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int val : v[par])
        {
            if (vis[val] == false)
            {
                q.push(val);
                vis[val] = true;
                des[val] = des[par] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(des, -1, sizeof(des));
    int ci, cj;
    cin >> ci >> cj;
    bfs(ci);
    cout << des[cj] << endl;
    return 0;
}