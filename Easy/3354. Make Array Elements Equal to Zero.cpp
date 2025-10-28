class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }

        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(nums[i]==0){
                int leftSum=currSum;
                int rightSum=totalSum-currSum;
                if(leftSum==rightSum){
                    ans+=2;
                }
                else if(abs(leftSum-rightSum)==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
