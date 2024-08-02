#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1005;
bool vis[N][N];
ll n, m;
char ads[N][N];

vector<pair<int, int>> vc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + vc[i].first;
        int cj = sj + vc[i].second;

        if (valid(ci, cj) && vis[ci][cj] == false && ads[ci][cj] == '.')
        {
            cnt += dfs(ci, cj);
            
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> m;
    ll mn = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ads[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ads[i][j] == '.' && vis[i][j] == false)
            {

                int ans = dfs(i, j);
                if (mn == -1 || ans < mn)
                {
                    mn = ans;
                }
            }
        }
    }
    cout << mn << endl;
    return 0;
}