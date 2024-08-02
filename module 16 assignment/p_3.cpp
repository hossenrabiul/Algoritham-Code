#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
int n, m;
char a[100][100];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i > n || j < 0 || j > m)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void dfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && vis[ci][cj] == false && a[ci][cj] == '.')
        {

            if (vis[di][dj])
            {
                return;
            }
            if (i == 0)
            {
                a[ci][cj] = 'r';
            }
            else if (i == 1)
            {
                a[ci][cj] = 'l';
            }
            else if (i == 2)
            {
                a[ci][cj] = 'u';
            }
            else if (i == 3)
            {
                a[ci][cj] = 'd';
            }
            dfs(ci, cj, di, dj);
        }
    }
}
int main()
{

    cin >> n >> m;

    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(si, sj, di, dj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'r' || a[i][j] == 'l' || a[i][j] == 'u' || a[i][j] == 'd')
            {
                a[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}