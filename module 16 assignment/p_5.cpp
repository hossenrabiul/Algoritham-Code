#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool vis[N][N];
char a[N][N];
vector<pair<int, int>> path = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}
int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int area = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i].first;
        int cj = sj + path[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            area += dfs(ci, cj);
        }
    }
    return area;
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
    int minArea = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == '.')
            {
                int componentArea = dfs(i, j);
                if (minArea == -1 || componentArea < minArea)
                {
                    minArea = componentArea;
                }
            }
        }
    }
    cout << minArea;
    return 0;
}