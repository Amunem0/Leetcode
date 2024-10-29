class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,
              vector<vector<int>>& dp) {
        if (i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int maxMoves = 0;
        vector<vector<int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
        for (auto &direction : directions) {
            int new_i = i + direction[0];
            int new_j = j + direction[1];
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 &&
                new_j < grid[0].size() && grid[new_i][new_j] > grid[i][j]) {
                maxMoves = max(maxMoves, 1 + solve(grid, new_i, new_j, dp));
            }
        }
        return dp[i][j] = maxMoves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < m; i++) {
            ans = max(ans, solve(grid, i, 0, dp));
        }
        return ans;
    }
};
