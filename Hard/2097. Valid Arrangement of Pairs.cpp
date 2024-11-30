class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj; // adjancency list

        unordered_map<int, int> indegree, outdegree;

        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

            // start node
            int startNode = pairs[0][0];
            for (auto& it:adj) {
                int node = it.first;
                if (outdegree[node] - indegree[node] == 1) {
                    startNode = node;
                    break;
                }
            }

            // Perform DFS

            vector<int> EulerPath;
            stack<int> st;
            st.push(startNode);

            while (!st.empty()) {
                int curr = st.top();
                if (!adj[curr].empty()) {
                    int neighbour = adj[curr].back();
                    adj[curr].pop_back();
                    st.push(neighbour);
                } else {
                    EulerPath.push_back(curr);
                    st.pop();
                }
            }

            reverse(EulerPath.begin(), EulerPath.end());
            vector<vector<int>> ans;

            for(int i = 1; i < EulerPath.size(); i++) {
                ans.push_back({EulerPath[i - 1], EulerPath[i]});
            }
        return ans;
    }
};
