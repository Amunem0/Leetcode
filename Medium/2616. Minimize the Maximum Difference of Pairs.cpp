class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int p) {
        int n = nums.size();
        int i = 0;
        int countPairs = 0;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                countPairs++;
                i += 2;
            } else {
                i++;
            }
        }
        return countPairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n - 1] - nums[0];
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
