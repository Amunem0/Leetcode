class Solution {
public:
    bool solve(vector<int>& nums, int mid, int maxOperations) {
        int totalOperations = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ops = nums[i] / mid;
            if (nums[i] % mid == 0) {
                ops -= 1;
            }
            totalOperations+=ops;
        }
        return totalOperations <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (solve(nums, mid, maxOperations)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
