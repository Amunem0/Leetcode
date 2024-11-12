class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        int maxBeautySeen=items[0][1];
        for(int i=1;i<n;i++){
            if(maxBeautySeen>items[i][1]){
                items[i][1]=maxBeautySeen;
            }
            maxBeautySeen=max(maxBeautySeen,items[i][1]);
        }

        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            int query=queries[i];
            int maxAns=0;
            int left=0;
            int right=n-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(items[mid][0]<=query){
                    maxAns=items[mid][1];
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            ans.push_back(maxAns);
        }
        return ans;
    }
};
