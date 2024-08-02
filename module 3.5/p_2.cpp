#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
bool vis[100];
int cnt = 0;
vector<int> vc;
void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for (int child : v[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
     vc.push_back(cnt);
   
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
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
           
            dfs(i);
            
        }
    }

    for (int i : vc)
    {
        cout << i << " ";
    }
    // cout<<cnt;
    return 0;
}