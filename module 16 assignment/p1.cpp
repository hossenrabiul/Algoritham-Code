
#include <bits/stdc++.h>
using namespace std;

const int N = 45;
int n;
char v[N][N];
bool vis[N][N];
char dir[N][N];

class Dir
{
public:
    int first;
    int second;
    char d;

    Dir(int f, int s, char d)
    {
        this->first = f;
        this->second = s;
        this->d = d;
    }
};

pair<int, int> s;
pair<int, int> e;

vector<Dir> d = {Dir(-1, 0, 'U'),
                 Dir(1, 0, 'D'),
                 Dir(0, -1, 'L'),
                 Dir(0, 1, 'R')};

bool isValid(int ci, int cj)
{
    return ci >= 0 && cj >= 0 && ci < n && cj < n;
}

void BFS(pair<int, int> src)
{
    vis[src.first][src.second] = true;
    queue<pair<int, int>> q;
    q.push(src);

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();

        for (int i = 0; i < d.size(); i++)
        {
            int ni = top.first + d[i].first;
            int nj = top.second + d[i].second;

            if (isValid(ni, nj) && !vis[ni][nj] && v[ni][nj] != 'O')
            {
                vis[ni][nj] = true;
                dir[ni][nj] = d[i].d;

                q.push({ni, nj});
            }
        }
    }
}

int main()
{

    cin >> n;

    memset(vis, false, sizeof(vis));
    memset(dir, '-', sizeof(dir));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char inp;
            cin >> inp;
            v[i][j] = inp;

            if (inp == '@')
            {
                s = {i, j};
            }

            if (inp == 'X')
            {
                e = {i, j};
            }
        }
    }

    BFS(s);

    if (vis[e.first][e.second])
    {
        int a = e.first;
        int b = e.second;
        while (dir[a][b] != '-')
        {

            if (dir[a][b] == 'U')
            {
                dir[a][b] = 'X';
                a += 1;
            }
            else if (dir[a][b] == 'D')
            {
                dir[a][b] = 'X';
                a -= 1;
            }
            else if (dir[a][b] == 'L')
            {
                dir[a][b] = 'X';
                b += 1;
            }
            else
            {
                dir[a][b] = 'X';
                b -= 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dir[i][j] == 'X')
                {
                    v[i][j] = '+';
                }
            }
        }

        cout << "Y\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "N\n";
    }

    return 0;
}