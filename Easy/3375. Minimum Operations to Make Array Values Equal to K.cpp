class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int &num:nums){
            if(num<k){
                return -1;
            }
            else if(num!=k){
                freq[num]++;
            }
        }
        return freq.size();
    }
};
