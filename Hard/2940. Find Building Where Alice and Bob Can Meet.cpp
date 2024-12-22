class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        int querySize=queries.size();

        vector<int>ans(querySize,-1);
        unordered_map<int,vector<pair<int,int>>>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<querySize;i++){
            int alice=queries[i][0];
            int bob=queries[i][1];

            if(alice<bob && heights[alice]<heights[bob]){
                ans[i]=bob;
            }
            else if(alice>bob && heights[alice]>heights[bob]){
                ans[i]=alice;
            }

            else if(alice==bob){
                ans[i]=alice;
            }

            else{
                mp[max(alice,bob)].push_back({max(heights[alice],heights[bob]),i});
            }
        }

            for(int i=0;i<n;i++){
                while(!pq.empty() &&pq.top().first<heights[i]){
                    ans[pq.top().second]=i;
                    pq.pop();
                }

                for(auto &it:mp[i]){
                    pq.push(it);
                }
            }
            return ans;
    }
};
