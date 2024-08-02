#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool flag;
ll knapsak(ll n, ll val)
{
    if (val == n)
    {
        flag = true;
        return n;
    }
    if (val > n)
    {
        return 0;
    }

    ll op1 = knapsak(n, val * 10);
    ll op2 = knapsak(n, val * 20);
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
        flag = false;
        ll ans = knapsak(n, 1);
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