class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(j-i+1==3){
                if(2*(nums[i]+nums[i+2])==nums[i+1]){
                    ans++;
                    cout<<i<<endl;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
