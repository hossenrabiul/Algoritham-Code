#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x;
    cin >> x;
    vector<int> vc;
    for (int val : v[x])
    {
        vc.push_back(val);
    }
    cout << vc.size();

    return 0;
}