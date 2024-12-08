class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int currEndTime) {
        int left = 0;
        int right = events.size() - 1;
        int ans = events.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (events[mid][0] > currEndTime) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& events, int ind, int n, int count, vector<vector<int>>& dp) {
        if (count == 2 || ind >= n) {
            return 0;
        }

        if (dp[ind][count] != -1) {
            return dp[ind][count];
        }
        int validInd = binarySearch(events, events[ind][1]);
        int take = events[ind][2] + solve(events, validInd, n, count + 1, dp);
        int notTake = solve(events, ind + 1, n, count, dp);
        return dp[ind][count] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int count = 0;
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(events, 0, n, count, dp);
    }
};
