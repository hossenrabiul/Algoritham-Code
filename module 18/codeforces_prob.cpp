#include <bits/stdc++.h>
using namespace std;
int knapsk(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (weight[n] <= w)
    {
        int op1 = knapsk(n - 1, weight, value, w - weight[n]) + value[n];
        int op2 = knapsk(n - 1, weight, value, w);
        return max(op1, op2);
    }
    else
    {
        int op2 = knapsk(n - 1, weight, value, w);
        return op2;
    }
}
int main()
{
    int n, w;
    cin >> n >> w;
    int Weight[n], value[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> Weight[i] >> value[i];
    }
    cout << knapsk(n, Weight, value, w) << endl;
    return 0;
}