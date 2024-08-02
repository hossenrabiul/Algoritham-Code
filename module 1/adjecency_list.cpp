#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    // for (int x : mat[0])
    // {
    //     cout << x << " ";
    // }
    int x;
    cin >> x;
    for (int i = 0; i < mat[x].size(); i++)
    {
        cout << mat[x][i] << " ";
    }
    return 0;
}