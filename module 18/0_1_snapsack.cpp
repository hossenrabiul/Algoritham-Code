#include <bits/stdc++.h>
using namespace std;
int knasack(int n, int Weight[], int Value[], int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (Weight[n] <= W)
    {
        // duta option
        //  1.nibo 2.nki nobo na
        int op1 = knasack(n - 1, Weight, Value, W - Weight[n])  + Value[n];
        int op2 = knasack(n - 1, Weight, Value, W);
        return max(op1, op2);
    }
    else
    {
        // 1ta option
        // bad dite
        int op2 = knasack(n - 1, Weight, Value, W);
        return op2;
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
    cout << knasack(n-1, Weight, Value, W) << endl;
    return 0;
}