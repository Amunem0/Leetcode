class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int currSum=nums[0];
        int maxSubarrSum=nums[0];

        for(int i=1;i<n;i++){
            currSum=max(nums[i],currSum+nums[i]);
            maxSubarrSum=max(maxSubarrSum,currSum);
        }

        currSum=nums[0];
        int minSubarrSum=nums[0];

        for(int i=1;i<n;i++){
            currSum=min(nums[i],currSum+nums[i]);
            minSubarrSum=min(minSubarrSum,currSum);
        }

        return max(abs(maxSubarrSum),abs(minSubarrSum));
    }
};
