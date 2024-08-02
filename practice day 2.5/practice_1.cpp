#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
void dfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;
    bool flag = false;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int p = par.first;
        int level = par.second;
        if (p == des)
        {
            cout << level << endl;
            flag = true;
        }
        for (int child : v[p])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    if (flag)
    {
    }
    else
    {
        cout << "-1" << endl;
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

    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        memset(vis, false, sizeof(vis));
        dfs(src, des);
        // int x = des;
        // int sum = 0;
        // while (x != -1)
        // {
        //     sum++;
        //     x = pat[x];
        // }
        // cout << sum << endl;
    }

    return 0;
}