class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int exploreIsland(vector<vector<int>>& grid, int i, int j, int islandId) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1)
            return 0;

        grid[i][j] = islandId;
        int size = 1;

        for (auto& dir : directions) {
            int x = i + dir[0], y = j + dir[1];
            size += exploreIsland(grid, x, y, islandId);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        unordered_map<int, int> islandSizes;
        int islandId = 2, maxIsland = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int size = exploreIsland(grid, i, j, islandId);
                    islandSizes[islandId] = size;
                    maxIsland = max(maxIsland, size);
                    islandId++;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighboringIslands;
                    for (auto& dir : directions) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] > 1)
                            neighboringIslands.insert(grid[x][y]);
                    }

                    int newSize = 1;
                    for (int id : neighboringIslands)
                        newSize += islandSizes[id];

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
