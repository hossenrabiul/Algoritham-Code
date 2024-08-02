#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unboundent_knapsack(int n, int s, int val[], int wei[])
{
    if (n == 0 || s == 0)
    {
        return 0;
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (wei[n - 1] <= s)
    {
        int ch1 = val[n - 1] + unboundent_knapsack(n, s - wei[n - 1], val, wei);
        int ch2 = unboundent_knapsack(n - 1, s, val, wei);
        return max(ch1, ch2);
    }
    else
    {
        return unboundent_knapsack(n - 1, s, val, wei);
    }
}
int main()
{
    int n;
    cin >> n;
    int val[n], wei[n];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        wei[i] = i + 1;
    }
    cout << unboundent_knapsack(n, n, val, wei);
    return 0;
}