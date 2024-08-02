#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[100005];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> vc;
        if (v[x].size() > 0)
        {
            for (int child : v[x])
            {
                vc.push_back(child);
            }
            sort(vc.begin(), vc.end(), greater<int>());
            for (int val : vc)
            {
                cout << val << " ";
            }

            cout << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}