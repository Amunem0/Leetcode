class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    void dfs(int node, unordered_map<int, vector<int>> &adj, int parent, vector<int> &mark,
             int &countZero, int &countOne) {

        if (mark[node] == 0) {
            countZero++;
        } else {
            countOne++;
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                mark[neighbor] = (mark[node] == 0) ? 1 : 0;
                dfs(neighbor, adj, node, mark, countZero, countOne);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        unordered_map<int, vector<int>> adjA = getAdj(edges1);
        unordered_map<int, vector<int>> adjB = getAdj(edges2);

        vector<int> markA(n, -1);
        markA[0] = 0;

        int countZeroA = 0;
        int countOneA = 0;

        dfs(0, adjA, -1, markA, countZeroA, countOneA);

        vector<int> markB(m, -1);
        markB[0] = 0;

        int countZeroB = 0;
        int countOneB = 0;

        dfs(0, adjB, -1, markB, countZeroB, countOneB);

        int maxFromTreeB = max(countZeroB, countOneB);

        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            result[i] = (markA[i] == 0 ? countZeroA : countOneA) + maxFromTreeB;
        }

        return result;
    }
};
