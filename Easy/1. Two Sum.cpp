class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>mp;
        int sum=0;
        int sub=0;
        for(int i=0;i<n;i++){
            sum=nums[i];
            sub=target-sum;
            if(mp.find(sub)!=mp.end()){
                return {mp[sub],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    }
};
