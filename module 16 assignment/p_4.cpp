#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e3 + 5;
bool vis[N][N];
char mat[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
pair<int, int> parent[N][N];

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m || mat[ci][cj] == '#')
    {
        return false;
    }
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int ai = par.first;
        int aj = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = ai + d[i].first;
            int cj = aj + d[i].second;
            if (valid(ci, cj) && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {ai, aj};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj;
    int di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if (mat[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
            parent[i][j] = {-1, -1};
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(si, sj);

    pair<int, int> src = {-1, -1};
    pair<int, int> des = {di, dj};
    while (des != src)
    {
        mat[des.first][des.second] = 'X';
        des = {parent[des.first][des.second]};
    }

    mat[si][sj] = 'R';
    mat[di][dj] = 'D';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}