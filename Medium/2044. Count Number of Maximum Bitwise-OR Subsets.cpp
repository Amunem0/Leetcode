class Solution {
public:
    int solve(vector<int> nums, int ind, int maxOR, int currentOR) {
        if (ind >= nums.size()) {
            return currentOR == maxOR ? 1 : 0;
        }

        int include = solve(nums, ind + 1, maxOR, currentOR | nums[ind]);
        int notInclude = solve(nums, ind + 1, maxOR, currentOR);

        return include + notInclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = nums[0];
        for (int i = 1; i < n; i++) {
            maxOR = maxOR | nums[i];
        }

        return solve(nums, 0, maxOR, 0);
    }
};
