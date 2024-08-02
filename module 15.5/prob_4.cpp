#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int n;
bool vis[N][N];
char a[N][N];
pair<int, int> des[N][N];
vector<pair<int, int>> d = {{0, 1}, {0,-1}, {-1,0}, {1, 0}};
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < n && a[ci][cj] != 'O')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void dfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                des[ci][cj] = {par.first, par.second};
            }
        }
    }
}
int main()
{

    cin >> n;

    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '@')
            {
                si = i;
                sj = j;
                vis[i][j] = false;
            }
            if (a[i][j] == 'X')
            {
                di = i;
                dj = j;
                vis[i][j] = false;
            }
            vis[i][j] = false;
        }
    }

    dfs(si, sj);

    if (!vis[di][dj])
    {
        cout << "N" << endl;
        return 0;
    }

    pair<int, int> ds = {di, dj};
    pair<int, int> sc = {si, sj};
    vector<pair<int, int>> vc;

    while (ds != sc)
    {
        vc.push_back({ds.first, ds.second});
        ds = des[ds.first][ds.second];
    }
    reverse(vc.begin(), vc.end());

    for (auto x : vc)
    {
        a[x.first][x.second] = '+';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}