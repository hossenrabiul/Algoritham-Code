#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
char a[1005][1005];
vector<int> vc;
int cnt = 0;
int cnt1 = 0;
int n, m;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void dfs(int si, int sj)
{

    cnt++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;

        if (valid(ci, cj) == true && vis[ci][cj] == false && a[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && a[i][j] != '#')
            {

                cnt = 0;
                dfs(i, j);
                vc.push_back(cnt);
            }
        }
    }
    if (vc.size() < 1)
    {
        cout << "0" << endl;
    }
    else
    {
        sort(vc.begin(), vc.end());
        for (int val : vc)
        {
            cout << val << " ";
        }
    }

    return 0;
}