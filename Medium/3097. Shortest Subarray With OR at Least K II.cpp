class Solution {
public:

    void addInWindow(int number,vector<int>&bits){
        for(int i=0;i<32;i++){
            if((number>>i)&1){
                bits[i]++;
            }
        }
    }

    void removeFromWindow(int number,vector<int>&bits){
        for(int i=0;i<32;i++){
            if((number>>i)&1){
                bits[i]--;
            }
        }
    }

    int getDecimalVal(vector<int>&bits){
        int number=0;
        for(int i=0;i<32;i++){
            if(bits[i]>0){
                number|=1<<i;
            }
        }
        return number;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        int minLen=INT_MAX;
        vector<int>bits(32,0);

        while(right<n){
            addInWindow(nums[right],bits);
            while(left<=right && getDecimalVal(bits)>=k){
                minLen=min(minLen,right-left+1);
                removeFromWindow(nums[left],bits);
                left++;
            }
            right++;
        }
        return minLen==INT_MAX?-1:minLen;
    }
};
