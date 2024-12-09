class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> prefix(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == 0 && nums[i - 1] % 2 == 0 || nums[i] % 2 != 0 && nums[i - 1] % 2 != 0) {
                continue;
            } else {
                prefix[i]+=prefix[i-1];
            }
        }
        for (auto query : queries) {
            bool flag = false;
            int start = query[0];
            int end = query[1];  
            if(end-start+1<=prefix[end]){
                flag=true;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};
