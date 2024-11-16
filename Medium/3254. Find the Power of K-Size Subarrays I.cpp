class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 1;
        vector<int> ans(n - k + 1, -1);
        for (int i = 1; i < k; i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                count++;
            } else {
                count = 1;
            }
        }
        if (count == k) {
            ans[0] = nums[k - 1];
        }
        int left = 1;
        int right = k;

        while (right < n) {
            if (nums[right - 1] + 1 == nums[right]) {
                count++;
            } else {
                count = 1;
            }

            if (count >= k) {
                ans[left] = nums[right];
            }
            left++;
            right++;
        }
        return ans;
    }
};
