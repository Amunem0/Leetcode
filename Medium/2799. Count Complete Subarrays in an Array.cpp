class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;

        int i=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int count=0;
        int distinct=st.size();
        st.clear();
        while(i<n){
            unordered_map<int,int>mp;
            int unique=0;
            int j=i;
            while(j<n){
                mp[nums[j]]++;
                if(mp[nums[j]]==1){
                    unique++;
                }
                if(unique==distinct){
                    count++;
                }
                j++;
            }
            i++;
        }
        return count;
    }
};
