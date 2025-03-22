class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>>&adj,vector<bool>&visited,int &numVertices,int &numEdges){
        visited[node]=true;
        numVertices++;
        numEdges+=adj[node].size();

        for(int &neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,adj,visited,numVertices,numEdges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<bool>visited(n,false);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            int vertices=0;
            int ed=0;
            dfs(i,adj,visited,vertices,ed);

            if(vertices*(vertices-1)/2==ed/2){
                ans++;
            }
        }
        return ans;
    }
};
