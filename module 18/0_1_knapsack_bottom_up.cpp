#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Weight[n], Value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Value[i];
    }
    int W;
    cin >> W;
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (Weight[i - 1] <= j)
            {
                int op1 = dp[i - 1][j - Weight[i - 1]] + Value[i - 1];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //  cout << dp[n][W];
    return 0;  
}