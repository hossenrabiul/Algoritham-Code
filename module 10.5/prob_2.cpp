#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j : v[i])
        {
            cout << j << " ";
        }
    }
    return 0;
}