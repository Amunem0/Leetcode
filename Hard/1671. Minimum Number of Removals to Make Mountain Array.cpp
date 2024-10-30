class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS(n,1);
        vector<int>LDS(n,1);


        //Longest Increasing Subsequence at a particular index
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if (nums[j] < nums[i]){
                    LIS[i]=max(LIS[i],1+LIS[j]);
                }     
            }
        }

        //Longest Decreasing Subsequence at a particular index
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if (nums[j] < nums[i]) {
                    LDS[i] = max(LDS[i], 1 + LDS[j]);
                }
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            if (LIS[i] > 1 && LDS[i] > 1){
                ans=min(ans,n-LIS[i]-LDS[i]+1);
            }  
        }

        return ans;
    }
    
};
