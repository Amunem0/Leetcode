class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int x, int y, vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        que.push({x, y});
        int fishCount = grid[x][y];
        grid[x][y] = 0;

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();

            for (const auto& dir : directions) {
                int newX = i + dir[0];
                int newY = j + dir[1];

                if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] > 0) {
                    que.push({newX, newY});
                    fishCount += grid[newX][newY];
                    grid[newX][newY] = 0;
                }
            }
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, bfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};
