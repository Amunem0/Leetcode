class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int minInd=0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[minInd]>k){
                minInd=i;
                count++;
            }
        }
        return count+1;
    }
};
