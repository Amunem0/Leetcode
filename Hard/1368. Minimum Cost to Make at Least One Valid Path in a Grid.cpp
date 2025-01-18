class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));

        minHeap.push({0, 0, 0});
        cost[0][0] = 0;

        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int currentCost = current[0];
            int x = current[1];
            int y = current[2];

            if (cost[x][y] < currentCost) {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int newX = x + directions[d][0];
                int newY = y + directions[d][1];

                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                    int gridDirection = grid[x][y];
                    int directionCost = ((gridDirection - 1 != d) ? 1 : 0);

                    int newCost = currentCost + directionCost;

                    if (newCost < cost[newX][newY]) {
                        cost[newX][newY] = newCost;
                        minHeap.push({newCost, newX, newY});
                    }
                }
            }
        }

        return cost[rows - 1][cols - 1];
    }
};
