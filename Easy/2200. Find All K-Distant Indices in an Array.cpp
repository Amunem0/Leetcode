class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            if(nums[i]==key){
                st.insert(i);
            }
        }

        vector<int>ans;

        for(int i=0;i<n;i++){
            for(auto &index:st){
                if(abs(i-index)<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
