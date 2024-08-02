#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int dp[100005];
bool flag;
ll knaspk(ll n, ll val)
{
    if (n == val)
    {
        flag = true;
        return n;
    }
    if (n < val)
    {
        return 0;
    }
    if (dp[val] != -1)
    {
        return dp[val];
    }
    int op1 = knaspk(n, val + 3);
    dp[val] = op1;
    int op2 = knaspk(n, val * 2);
    dp[val] = op2;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        flag = false;
        knaspk(n, 1);
        if (flag)
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