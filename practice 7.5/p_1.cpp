#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ads[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                ads[i][j] = 0;
            }
            else
            {
                ads[i][j] = 100;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ads[u][v] = c;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ads[i][j] != 100 && ads[i][k] + ads[k][j] < ads[i][j])
                {
                    ads[i][j] = ads[i][k] + ads[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ads[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}