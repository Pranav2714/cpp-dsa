#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &a, unordered_map<int, vector<int>> &adj, vector<int> &res, vector<bool> &v, int u)
    {
        if (v[u])
            return;
        v[u] = true;
        for (auto &x : adj[u])
        {
            if (!v[x])
            {
                res.push_back(x);
                dfs(a, adj, res, v, x);
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>> &a)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < a.size(); i++)
        {
            adj[i] = a[i];
        }
        vector<bool> v(a.size(), false);
        vector<int> res;
        res.push_back(0); // start DFS from node 0
        dfs(a, adj, res, v, 0);
        return res;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjList(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // remove if directed graph
    }

    Solution sol;
    vector<int> dfsTraversal = sol.dfsOfGraph(adjList);

    for (int node : dfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
