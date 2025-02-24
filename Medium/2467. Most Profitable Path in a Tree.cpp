class Solution {
public:
    int DFSBob(int curr, int t, vector<bool>& visited, unordered_map<int, vector<int>>& adj, unordered_map<int, int>& bobMap) {
        visited[curr] = true;
        bobMap[curr] = t;

        if (curr == 0) return true;

        for (int ngbr : adj[curr]) {
            if (!visited[ngbr] && DFSBob(ngbr, t + 1, visited, adj, bobMap)) {
                return true;
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount,
                  unordered_map<int, vector<int>>& adj, unordered_map<int, int>& bobMap, int& maxIncome) {
        visited[curr] = true;

        if (!bobMap.count(curr) || t < bobMap[curr]) {
            income += amount[curr];
        } else if (t == bobMap[curr]) {
            income += amount[curr] / 2;
        }

        if (adj[curr].size() == 1 && curr != 0) {
            maxIncome = max(maxIncome, income);
        }

        for (int ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, visited, amount, adj, bobMap, maxIncome);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> bobMap;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        DFSBob(bob, 0, visited, adj, bobMap);
        
        int maxIncome = INT_MIN;
        visited.assign(n, false);
        DFSAlice(0, 0, 0, visited, amount, adj, bobMap, maxIncome);

        return maxIncome;
    }
};
