class Solution {
public:
    #define PP pair<int,pair<int,int>>
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();

        priority_queue<PP,vector<PP>,greater<>>pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int row=0;row<m;row++){
            for(int col:{0,n-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        for(int col=0;col<n;col++){
            for(int row:{0,m-1}){
                pq.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        int water=0;
        vector<vector<int>> directions={{0,-1},{0,1},{-1,0},{1,0}};
        while(!pq.empty()){
            auto pp=pq.top();
            pq.pop();

            int height=pp.first;
            int i=pp.second.first;
            int j=pp.second.second;

            //find neighbours
            for(vector<int>&dir:directions){
                int newi=i+dir[0];
                int newj=j+dir[1];

                if(newi>=0 && newi<m && newj>=0 && newj<n && !visited[newi][newj]){
                    water+=max(height-heightMap[newi][newj],0);

                    pq.push({max(height,heightMap[newi][newj]),{newi,newj}});
                    visited[newi][newj]=true;
                }
            }
        }
        return water;
    }
};
