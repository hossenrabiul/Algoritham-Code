#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[50][50];
int dis[50][50];
char a[50][50];
int n;
vector<pair<int, int>> v = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> pq;
    pq.push({si, sj});

    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.front();
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int ji = parent.first + v[i].first;
            int jj = parent.second + v[i].second;

            if (valid(ji, jj) && vis[ji][jj] == false && a[ji][jj] != 'T')
            {
                pq.push({ji, jj});
                vis[ji][jj] = true;
                dis[ji][jj] = dis[parent.first][parent.second] + 1;
            }
        }
    }
}
int main()
{

    while (cin >> n)
    {
        int si, sj, di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        bfs(si, sj);
        cout << dis[di][dj] << endl;
    }
    return 0;
}