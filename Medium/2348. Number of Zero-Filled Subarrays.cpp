class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long i=0;
        long long j=0;
        long long ans=0;

        while(j<n){
            if(nums[j]==0){
                ans+=j-i+1;
            }
            if(nums[j]!=0){
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};
