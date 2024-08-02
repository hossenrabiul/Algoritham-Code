#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
void dfs(int src,int des)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    vis[src] = true; 
    bool paici = false;
    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        // cout << pr << endl;
        
        int pr = p.first;
        int level = p.second;
        if(des == pr)
        {
            cout << level;
            paici = true;
        }
        for (int i = 0; i < v[pr].size(); i++)
        {
            int child = v[pr][i];

            if (vis[child] == false)
            {
                q.push({child,level+1});
                vis[child] = true;
            }
        }
    }
    if(paici == false)
    {
        cout << "-1";
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
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    dfs(src,2);
   
    return 0;
}