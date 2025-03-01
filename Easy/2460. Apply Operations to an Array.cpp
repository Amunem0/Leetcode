class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int j=1;
        while(j<n){
            if(nums[i]==nums[j]){
                nums[i]*=2;
                nums[j]=0;
            }
            i++;
            j++;
        }
        
        int nonZeroInd=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[nonZeroInd]=nums[i];
                nonZeroInd++;
            }
        }

        while(nonZeroInd<n){
            nums[nonZeroInd]=0;
            nonZeroInd++;
        }
        return nums;
    }
};
