class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();

        vector<vector<int>>height(m,vector<int>(n,-1)); 
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j}); 
                }
            }
        }

        vector<vector<int>>directions{{0,1},{0,-1},{-1,0},{1,0}};

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto curr=q.front();
                q.pop();

                int i=curr.first;
                int j=curr.second;

                for(auto &dir:directions){
                    int newi=i+dir[0];
                    int newj=j+dir[1];

                    if(newi>=0 && newi<m && newj>=0 && newj<n && height[newi][newj]==-1){
                        height[newi][newj]=height[i][j]+1;
                        q.push({newi,newj});
                    }
                }
            }
        }
        return height;
    }
};
