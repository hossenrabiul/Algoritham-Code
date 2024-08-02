#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
char a[1005][1005];
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
    int sr, sc, dr, dc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
            if (a[i][j] == 'B')
            {
                dr = i;
                dc = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(sr, sc);
    if (vis[dr][dc] == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}