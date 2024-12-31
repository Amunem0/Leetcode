class Solution {
public:
    int solve(int ind, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (ind >= days.size()) {
            return 0;
        }

        if (dp[ind] != -1) {
            return dp[ind];
        }
        int oneDay = costs[0] + solve(ind + 1, days, costs, dp);

        int i = ind;
        while (i < days.size() && days[i] < days[ind] + 7) {
            i++;
        }
        int sevenDays = costs[1] + solve(i, days, costs, dp);

        i = ind;
        while (i < days.size() && days[i] < days[ind] + 30) {
            i++;
        }
        int thirtyDays = costs[2] + solve(i, days, costs, dp);

        return dp[ind] = min({oneDay, sevenDays, thirtyDays});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(days.size() + 1, -1);
        return solve(0, days, costs, dp);
    }
};
