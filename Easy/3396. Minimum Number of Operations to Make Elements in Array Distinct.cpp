class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(101,0);
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            while(freq[nums[i]]>1){
                freq[nums[j]]--;
                if(j+1<n){
                    freq[nums[j+1]]--;
                }
                if(j+2<n){
                    freq[nums[j+2]]--;
                }
                j+=3;
                ans+=1;
            }
        }

        return ans;
        
    }
};
