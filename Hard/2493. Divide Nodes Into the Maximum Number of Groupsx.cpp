class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int node, vector<int> &colors, int color) {
        colors[node] = color;

        for (int &neighbor : adj[node]) {
            if (colors[neighbor] == colors[node]) 
                return false;

            if (colors[neighbor] == -1) {
                if (!isBipartite(adj, neighbor, colors, 1 - color))
                    return false;
            }
        }

        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int start, int n) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;

        int level = 1; // Max groups in the component
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();

                for (int &neighbor : adj[node]) {
                    if (visited[neighbor]) continue;
                    
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            level++;
        }

        return level - 1;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>> &adj, int node, vector<bool> &visited, vector<int> &levels) {
        int maxGroup = levels[node];
        visited[node] = true;

        for (int &neighbor : adj[node]) {
            if (!visited[neighbor]) {
                maxGroup = max(maxGroup, getMaxFromEachComp(adj, neighbor, visited, levels));
            }
        }

        return maxGroup;
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj; 

        // Building adjacency list
        for (auto &edge : edges) {
            int u = edge[0] - 1; // Converting to 0-based index
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Bipartite check
        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (!isBipartite(adj, node, colors, 1))
                    return -1;
            }
        }

        // BFS to find max levels for each node
        vector<int> levels(n, 0);
        for (int node = 0; node < n; node++) {
            levels[node] = bfs(adj, node, n);
        }

        // Get max group count from each component
        int maxGroupEachComp = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
            }
        }

        return maxGroupEachComp;
    }
};
