#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> ads[N];
bool vis[N];
int parentArray[N];
bool ans;
void dfs(int parent)
{
    vis[parent] = true;
    // cout << parent << " ";
    for (int child : ads[parent])
    {
        if(vis[child] == true && child != parentArray[parent])
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            parentArray[child] = parent;
            dfs(child);
            
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
            dfs(i);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << parentArray[i] << " ";
    // }
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