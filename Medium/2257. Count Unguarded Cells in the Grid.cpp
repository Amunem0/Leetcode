class Solution {
public:
    void mark(int row, int col, vector<vector<int>>& matrix) {
        // up
        for (int i = row - 1; i >= 0; i--) {
            if (matrix[i][col] == 2 || matrix[i][col] == 3) {
                break;
            }
            matrix[i][col] = 1;
        }

        // down
        for (int i = row + 1; i < matrix.size(); i++) {
            if (matrix[i][col] == 2 || matrix[i][col] == 3) {
                break;
            }
            matrix[i][col] = 1;
        }

        // left
        for (int j = col - 1; j >= 0; j--) {
            if (matrix[row][j] == 2 || matrix[row][j] == 3) {
                break;
            }
            matrix[row][j] = 1;
        }

        // right
        for (int j = col + 1; j < matrix[0].size(); j++) {
            if (matrix[row][j] == 2 || matrix[row][j] == 3) {
                break;
            }
            matrix[row][j] = 1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for (int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            matrix[x][y] = 2;
        }

        for (int i = 0; i < walls.size(); i++) {
            int x = walls[i][0];
            int y = walls[i][1];
            matrix[x][y] = 3;
        }

        for (int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            mark(x, y, matrix);
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
