#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        ll a, b, c;
        cin >> a >> b >> c;
        ads[a][b] = c;
    }

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
                // cout << "INF"
                //      << " ";
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