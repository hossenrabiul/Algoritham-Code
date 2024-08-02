#include <bits/stdc++.h>
using namespace std;
vector<int> ads[100];
bool vis[100];
int parentArray[100];
bool ans;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < ads[parent].size(); i++)
        {
            int child = ads[parent][i];

            if (vis[child] == true && parentArray[parent] != child)
            {
                ans = true;
            }
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parentArray[child] = parent;
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
        ads[a].push_back(b);
        ads[b].push_back(a);
    }
    ans = false;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    if (ans)
    {
        cout << "Cycle found";
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}
