class Solution {
public:
    #define P pair<long long,int>
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<P>>adj;

        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];

            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        priority_queue<P,vector<P>,greater<P>>pq; //min-Heap
        vector<long long>ans(n,LLONG_MAX);
        vector<int>pathCount(n,0);

        ans[0]=0;
        pathCount[0]=1;
        pq.push({0,0}); //{time,node}

        while(!pq.empty()){
            long long currTime=pq.top().first;
            int currNode=pq.top().second;

            pq.pop();

            for(auto &vec:adj[currNode]){
                int ngbr=vec.first;
                int roadTime=vec.second;

                if(currTime+roadTime<ans[ngbr]){
                    ans[ngbr]=currTime+roadTime;
                    pq.push({ans[ngbr],ngbr});
                    pathCount[ngbr]=pathCount[currNode];
                }
                else if(currTime+roadTime==ans[ngbr]){
                    pathCount[ngbr]=(pathCount[ngbr]+pathCount[currNode])%MOD;
                }
            }

        }
        return pathCount[n-1];
    }
};
