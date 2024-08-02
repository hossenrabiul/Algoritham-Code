#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> v[1000005];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int q;
    cin >> q;
    while (q--)
    {

        int A, B;
        cin >> A >> B;
        bool flag = false;
        for (int child : v[A])
        {
            if (child == B)
            {
                flag = true;
            }
        }

        if (flag == true || A == B)
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