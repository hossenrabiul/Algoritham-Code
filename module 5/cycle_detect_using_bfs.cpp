#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> ads[N];
bool vis[N];
int parentArray[N];
bool ans;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        // cout << parent << " ";
        for (int child : ads[parent])
        {
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
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}