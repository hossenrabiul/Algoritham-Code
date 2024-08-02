#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
using namespace std;
const ll N = 1e5 + 5;
vector<pi> v[N];
ll dis[N];
ll path[N];
class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void diskstra(int s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();
        ll parentNode = parent.first;
        ll parentdcost = parent.second;

        for (pi child : v[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (parentdcost + childCost < dis[childNode])
            {
                dis[childNode] = parentdcost + childCost;
                pq.push({childNode, dis[childNode]});
                path[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e18;
        path[i] = -1;
    }
    diskstra(1);
    if (dis[n] == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        ll x = n;
        vector<ll> vc;
        while (x != -1)
        {
            vc.push_back(x);
            x = path[x];
        }
        reverse(vc.begin(), vc.end());
        for (int ans : vc)
        {
            cout << ans << " ";
        }
    }
    return 0;
}