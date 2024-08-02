#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m;
bool vis[N][N];
char grit[N][N];
pair<int, int> path[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int cnt = 0;
bool IsValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && grit[x][y] != '#';
}

class person
{
public:
    int x;
    int y;
    char nm;
    person(int x, int y, char nm)
    {
        this->x = x;
        this->y = y;
        this->nm = nm;
    }
};
queue<person> q;
void bfs()
{
    while (!q.empty())
    {

        person head = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = head.x + d[i].first;
            int cj = head.y + d[i].second;

            if (IsValid(ci, cj) && vis[ci][cj] == false)
            {
                q.push(person(ci, cj, head.nm));
                vis[ci][cj] = true;
                grit[ci][cj] = head.nm;
                if (head.nm == 'A')
                {
                    path[ci][cj] = {d[i].first, d[i].second};
                }
            }
        }
    }
}

bool isChek(int i, int j)
{
    return i == 0 || j == 0 || i == n - 1 || j == m - 1;
}
int main()
{
    cin >> n >> m;
    int sx, sy;
    int dx, dy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grit[i][j];

            if (grit[i][j] == 'M')
            {
                q.push(person(i, j, 'M'));
                vis[i][j] = true;
            }

            if (grit[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
        }
    }
    q.push(person(sx, sy, 'A'));
    vis[sx][sy] = true;
    bfs();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isChek(i, j) && grit[i][j] == 'A')
            {
                dx = i;
                dy = j;
                flag = false;
            }
        }
    }
    if (flag)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        cout << "YES" << endl;
    }

    pair<int, int> coords = {dx, dy};
    pair<int, int> src = {sx, sy};
    vector<pair<int, int>> ans;
    while (coords != src)
    {
        ans.push_back({path[coords.first][coords.second]});
        coords.first -= ans.back().first;
        coords.second -= ans.back().second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto val : ans)
    {
        if (val.first == 0 && val.second == 1)  cout << "L";
        if (val.first == 0 && val.second == -1) cout << "R";
        if (val.first == -1 && val.second == 0) cout << "U";
        if (val.first == 1 && val.second == 0)  cout << "D";
            
    }

    return 0;
}