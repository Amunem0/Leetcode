class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxElem=*max_element(nums.begin(),nums.end());
        vector<int>freq(maxElem+1,0);
        int i=0,j=0;
        long long ans=INT_MIN;
        long long sum=0;

        while(j<n){
            sum+=nums[j];
            while(freq[nums[j]]>0){
                sum-=nums[i];
                freq[nums[i]]--;
                i++;
            }
            freq[nums[j]]++;
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};
