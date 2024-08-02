#include <bits/stdc++.h>
using namespace std;
bool vis[25][25];
char a[25][25];
int y, x;
int cnt;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i >= 0 && i < x && j >= 0 && j < y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void basicIO(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && vis[ci][cj] == false && a[ci][cj] != '#')
        {

            basicIO(ci, cj);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int si, sj;
    int cs = 1;
    while (n--)
    {
        cin >> y >> x;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        cnt = 0;
        basicIO(si, sj);
        cout << "case "<< cs++ << ": " << cnt << endl;
    }
    return 0;
}
