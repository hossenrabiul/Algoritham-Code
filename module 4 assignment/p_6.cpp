#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;

    int mat[n][n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }
    
    memset(mat, 0, sizeof(mat));

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b || mat[a][b] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}