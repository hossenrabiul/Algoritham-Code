#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll ads[n][n];
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
                ads[i][j] = INT_MAX;
            }
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ads[a][b] = c;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (ads[i][j] == INT_MAX)
    //         {
    //             cout << "INF ";
    //         }
    //         else
    //         {
    //             cout << ads[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ads[i][k] + ads[k][j] < ads[i][j])
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
            if (ads[i][j] == INT_MAX)
            {
                cout << "INF ";
            }
            else
            {
                cout << ads[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}