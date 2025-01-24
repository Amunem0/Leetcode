class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        // Traverse adjacent nodes
        for (auto it : graph[node]) {
            // If the node is not visited
            if (!vis[it]) {
                if (dfsCheck(it, graph, vis, pathVis, check)) {
                    check[node] = 0;
                    return true;
                }
            }
            // If the node is visited and part of the current path
            else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1; // Mark the node as safe
        pathVis[node] = 0; // Remove the node from the current path
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0), pathVis(V, 0), check(V, 0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
