class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefixSum(n,0);

        for(int i=0;i<n;i++){
            prefixSum[i]+=(i>0?prefixSum[i-1]:0)+nums[i];
        }

        int count=0;

        for(int i=0;i<n-1;i++){
            long long remainingSum=prefixSum[n-1]-prefixSum[i];
            if(prefixSum[i]>=remainingSum){
                count++;
            }
        }
        return count;
    }
};
