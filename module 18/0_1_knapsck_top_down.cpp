#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];
int knasack(int n, int Weight[], int Value[], int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (Weight[n] <= W)
    {
        // duta option
        //  1.nibo 2.nki nobo na
        int op1 = knasack(n - 1, Weight, Value, W - Weight[n]) + Value[n];
        int op2 = knasack(n - 1, Weight, Value, W);
        dp[n][W] = max(op1, op2);
        return dp[n][W];
    }
    else
    {
        // 1ta option
        // bad dite
        int op2 = knasack(n - 1, Weight, Value, W);
        return dp[n][W] = op2;
    }
}
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
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knasack(n - 1, Weight, Value, W) << endl;
    return 0;
}