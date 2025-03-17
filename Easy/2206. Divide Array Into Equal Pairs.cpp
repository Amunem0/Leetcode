class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int>freq(501);
        int n=nums.size();
        for(auto &num:nums){
            freq[num]++;
        }

        for(int i=0;i<freq.size();i++){
            if(freq[i]%2!=0){
                return false;
            }
        }
        return true;
    }
};
