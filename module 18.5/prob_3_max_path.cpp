#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100][100];
int knap(int si, int sj)
{
    if (si > n || sj > m)
    {
        return 0;
    }
    if (si == n && sj == m)
    {
        return a[n][m];
    }
    int op1 = knap(si + 1, sj) + a[si][sj];
    int op2 = knap(si, sj + 1) + a[si][sj];
    return max(op1, op2);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << knap(1, 1);
    return 0;
}