#include <bits/stdc++.h>
using namespace std;
const int N = 10005;

int dp[N][N];
int knapsk(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        int op1 = knapsk(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];
        int op2 = knapsk(n - 1, weight, value, w);
        dp[n][w] = max(op1, op2);
        return dp[n][w];
    }
    else
    {
        return dp[n][w] = knapsk(n - 1, weight, value, w);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int weight[n], value[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << knapsk(n, weight, value, w) << endl;
    }

    return 0;
}