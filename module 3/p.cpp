//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool visit[10000];
    vector<int> BFS(int src, vector<int> adj[])
    {
        queue<int> q;
        q.push(src);
        visit[src] = true;

        vector<int> mylevels;
        while (!q.empty())
        {
            int par = q.front();
            q.pop();
            mylevels.push_back(par);

            for (int child : adj[par])
            {
                if (!visit[child])
                {
                    q.push(child);
                    visit[child] = true;
                }
            }
        }
        return mylevels;
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        memset(visit, false, sizeof(visit));
        return BFS(0, adj);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends