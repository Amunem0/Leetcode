class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u, int v) {
        visited[u] = true;

        if (u == v) {
            return true;
        }

        for (auto& neighbor : adj[u]) {
            if (!visited[neighbor]) {
                if (dfs(adj, visited, neighbor, v)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool>visited (n,false);
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj, visited, u, v)) {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
