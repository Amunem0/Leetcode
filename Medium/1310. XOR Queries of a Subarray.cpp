class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto query:queries){
            int left=query[0];
            int right=query[1];

            int xorr=arr[left];

            for(int i=left+1;i<=right;i++){
                xorr^=arr[i];
            }
            ans.push_back(xorr);
        }
        return ans;
    }
};
