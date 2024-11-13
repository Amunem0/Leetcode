class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int indlow =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin(); // Gives the first element not less than
                              // (lower-nums[i])
            int x = indlow - 1 - i;

            int indup =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin(); // Gives the first element greater than
                              // (upper-nums[i])
            int y = indup - 1 - i;

            ans += (y - x);
        }
        return ans;
    }
};
