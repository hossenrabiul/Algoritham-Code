#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
int n, m;
char a[100][100];
int cnt = 0;
vector<char> vc;
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
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && vis[ci][cj] == false && a[ci][cj] != '#')
        {

            if (vis[di][dj])
            {
                return;
            }
            if (i == 0)
            {
                vc.push_back('R');
            }
            else if (i == 1)
            {
                vc.push_back('L');
            }
            else if (i == 2)
            {
                vc.push_back('U');
            }
            else if (i == 3)
            {
                vc.push_back('D');
            }
            dfs(ci, cj, di, dj);
            cnt++;
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
            if (a[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(si, sj, di, dj);
    if (vis[di][dj])
    {
        cout << "YES" << endl;
    }
    cout << cnt << endl;
    for (char C : vc)
    {
        cout << C << " ";
    }
    return 0;
}