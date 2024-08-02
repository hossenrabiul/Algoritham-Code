#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 1e5 + 5;
vector<int> ads[N];
bool pathVisit[N];
bool vis[N];
bool ans;
void dfs(int parent)
{
    vis[parent] = true;
    pathVisit[parent] = true;
    for (int child : ads[parent])
    {
        if (pathVisit[child])
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
    pathVisit[parent] = false;
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
        // ads[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }
    if (ans)
    {
        cout << "Cycle detected";
    }
    else
    {
        cout << "Cycle not detected";
    }
    return 0;
}