#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
void dfs(int src, int l)
{
    queue<pair<int, int>> q;
    q.push({src, 1});
    vis[src] = true;
    vector<int> vc;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int p = par.first;
        int level = par.second;

        if (level == l)
        {
            for (int child : v[p])
            {

                if (vis[child] == false)
                {
                    vc.push_back(child);
                    vis[child] = true;
                }
            }
            sort(vc.begin(), vc.end(), greater<int>());
            for (int val : vc)
            {
                cout << val << " ";
            }
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
    // if (flag)
    // {
    // }
    // else
    // {
    //     cout << "-1" << endl;
    // }
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

    int l;
    cin >> l;
    memset(vis, false, sizeof(vis));
    dfs(0, l);

    return 0;
}