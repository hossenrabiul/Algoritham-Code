const int N = 1e5 + 5;
class Solution
{
    int group_size[N];
    int parent[N];
    bool ans;

public:
    void dsu_init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            group_size[i] = 1;
        }
    }
    int dsu_find(int node)
    {
        if (parent[node] == -1)
            return node;
        int leader = dsu_find(parent[node]);
        parent[node] = leader;
        return leader;
    }
    void dsu_union_by_size(int a, int b)
    {
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[])
    {
        dsu_init(n);
        ans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j : adj[i])
            {
                int leaderA = dsu_find(i);
                int leaderB = dsu_find(j);
                if (leaderA == leaderB)
                {
                    ans = true;
                    return ans;
                }
                else
                {
                    dsu_union_by_size(i, j);
                }
            }
        }
        return ans;
    }