class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vec(n);

        for(int i=0;i<n;i++){
            vec[i]={nums[i],i};
        }

        sort(begin(vec),end(vec));

        int minIndex=n;
        int maxWidth=0;

        for(int i=0;i<n;i++){
            minIndex=min(minIndex,vec[i].second);
            maxWidth=max(maxWidth,vec[i].second-minIndex);
        }
        return maxWidth;
    }
};
