class Solution {
public:
    int solve(vector<int>& nums, int target,int ind){
        if(ind==0){
            if(target==0 && nums[ind]==0){
                return 2;
            }
            if(target==nums[ind] || target==-nums[ind]){
                return 1;
            }
            return 0;
        }
        int pickPos=solve(nums,target+nums[ind],ind-1);
        int pickNeg=solve(nums,target-nums[ind],ind-1);

        return pickPos+pickNeg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,n-1);
    }
};
