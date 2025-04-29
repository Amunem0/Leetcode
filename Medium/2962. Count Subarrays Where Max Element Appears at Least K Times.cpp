class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxElem=*max_element(nums.begin(),nums.end());

        int i=0;
        int j=0;
        long long count=0;
        long long ans=0;
        while(j<n){
            if(maxElem==nums[j]){
                count++;
            }

            while(count>=k){
                ans+=n-j;
                if(maxElem==nums[i]){
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
