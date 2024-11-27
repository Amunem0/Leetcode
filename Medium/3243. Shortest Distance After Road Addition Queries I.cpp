class Solution {
public:
    int bfs(int n, unordered_map<int, vector<int>>& adj) {
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        int level = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int node = que.front();
                que.pop();

                if (node == n - 1) {
                    return level;
                }

                for (auto& neighbour : adj[node]) {
                    if (!visited[neighbour]) {
                        que.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            adj[i].push_back(i + 1);
        }

        int q = queries.size();
        vector<int> ans;

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            int d = bfs(n, adj);
            ans.push_back(d);
        }
        return ans;
    }
};
