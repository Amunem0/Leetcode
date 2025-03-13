class Solution {
public:
    int n, Q;

    bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < n) {
                diff[r + 1] -= x;
            }
        }

        int cumulativeSum = 0;
        for (int i = 0; i < n; i++) {
            cumulativeSum += diff[i];
            diff[i] = cumulativeSum;

            if (nums[i] - diff[i] > 0) {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        int l = 0, r = Q - 1, k = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canMakeZero(nums, queries, mid)) {
                k = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};
