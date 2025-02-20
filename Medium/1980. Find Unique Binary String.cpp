class Solution {
public:
    bool solve(int ind, int n, string& currStr, vector<string>& nums,
               string& ans) {
        if (ind == n) {
            if (find(nums.begin(), nums.end(), currStr) == nums.end()) {
                ans = currStr;
                return true;
            }
            return false;
        }

        for (char i = '0'; i <= '1'; i++) {
            currStr.push_back(i);
            if (solve(ind + 1, n, currStr, nums, ans) == true) {
                return true;
            }
            currStr.pop_back();
        }

        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string currStr = "";
        string ans = "";
        solve(0, n, currStr, nums, ans);

        return ans;
    }
};
