#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = INT_MIN; 
        int ans1 = INT_MIN;
        int ai, aj;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > ans)
            {
                ans = a[i];
                ai = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] > ans1)
            {
                if (a[i] != ans)
                {
                    aj = i;
                    ans1 = a[i];
                }
            }
        }
        if (ai<aj)
        {
            cout << ai << " " << aj << endl;
        }
        else
        {
            cout << aj << " " << ai << endl;
        }
    }
    return 0;
}