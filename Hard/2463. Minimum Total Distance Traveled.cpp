class Solution {
public:
    long long solve(vector<int>& robot, vector<int>& factories, int robotPos,
                    int factoriesPos, vector<vector<long long>>& dp) {
        if (robotPos < 0) {
            return 0;
        }
        if (factoriesPos < 0) {
            return 1e18;
        }
        if (dp[robotPos][factoriesPos] != -1) {
            return dp[robotPos][factoriesPos];
        }

        long long include =
            abs(robot[robotPos] - factories[factoriesPos]) +
            solve(robot, factories, robotPos - 1, factoriesPos - 1, dp);
        long long exclude =
            solve(robot, factories, robotPos, factoriesPos - 1, dp);

        return dp[robotPos][factoriesPos] = min(include, exclude);
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoriesOfOne;
        for (const auto& f : factory) {
            int pos = f[0];
            int count = f[1];
            for (int j = 0; j < count; ++j) {
                factoriesOfOne.push_back(pos);
            }
        }
        vector<vector<long long>> dp(
            robot.size() + 1, vector<long long>(factoriesOfOne.size() + 1, -1));
        return solve(robot, factoriesOfOne, robot.size() - 1,
                     factoriesOfOne.size() - 1, dp);
    }
};
