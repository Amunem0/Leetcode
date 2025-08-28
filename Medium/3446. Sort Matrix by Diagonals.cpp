class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> diagonal;
        int col = 1;

        while (col < n) {
            int currrow = 0;
            int dupcol = col;
            while (currrow < n - 1 && dupcol < n) {
                diagonal.push_back(grid[currrow][dupcol]);
                currrow++;
                dupcol++;
            }
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            currrow = 0;
            dupcol = col;
            while (currrow < n - 1 && dupcol < n) {
                grid[currrow][dupcol] = diagonal[diagonal.size() - 1];
                diagonal.pop_back();
                currrow++;
                dupcol++;
            }
            col++;
        }

        int row = 0;
        while (row < n) {
            int duprow = row;
            int currcol = 0;
            while (currcol < n && duprow < n) {
                diagonal.push_back(grid[duprow][currcol]);
                duprow++;
                currcol++;
            }
            sort(diagonal.begin(), diagonal.end());
            duprow = row;
            currcol = 0;
            while (currcol < n && duprow < n) {
                grid[duprow][currcol] = diagonal[diagonal.size() - 1];
                diagonal.pop_back();
                duprow++;
                currcol++;
            }
            row++;
        }
        return grid;
    }
};
