class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxLen=1;
        int bit_mask=0;
        while(j<n){
            while((bit_mask & nums[j])!=0){
                bit_mask^=nums[i];
                i++;
            }

            bit_mask |=nums[j];
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};
