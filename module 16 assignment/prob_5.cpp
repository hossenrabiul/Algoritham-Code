#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
bool vis[N][N];
char ads[N][N];
pair<int, int> par[N][N];
int n, m;

vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int ci, int cj)
{
    if (ci >= 1 && ci < n && cj >= 1 && cj < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    vis[src.first][src.second] = true;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + v[i].first;
            int cj = parent.second + v[i].second;

            if (valid(ci, cj) && vis[ci][cj] == false && ads[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                par[ci][cj] = parent;
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    pair<int, int> s;
    pair<int, int> d;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ads[i][j];
            if (ads[i][j] == 'R')
            {
                s = {i, j};
            }
            if (ads[i][j] == 'D')
            {
                d = {i, j};
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
    bfs(s);
 
    return 0;
}