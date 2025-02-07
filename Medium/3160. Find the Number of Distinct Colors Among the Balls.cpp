class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>ans;
        unordered_map<int,int>colmp; //color->count;
        unordered_map<int,int>ballmp; //ball- >colour

        
        for(auto query:queries){
            int ball=query[0];
            int colour=query[1];

            if(ballmp.count(ball)){ //already coloured
                int prevCol=ballmp[ball];
                colmp[prevCol]--;
                
                if(colmp[prevCol]==0){
                    colmp.erase(prevCol);
                }
            }

            ballmp[ball]=colour;
            colmp[colour]++;
            ans.push_back(colmp.size());
        }
        return ans;
    }
};
