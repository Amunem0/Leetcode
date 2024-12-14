class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long i=0;
        long long j=0;
        long long ans=0;
        map<long long,long long>mp;
        while(j<n){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first-mp.begin()->first)>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};
