APPROACH 1:
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> rowMins(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowMins[i] = min(rowMins[i], matrix[i][j]);
            }
        }

        vector<int> colMaxs(m, INT_MIN);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                colMaxs[j] = max(colMaxs[j], matrix[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                    return {matrix[i][j]};
                }
            }
        }

        return {};
    }
};


APPROACH 2:
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rowMinMax=INT_MIN;
        for(int i=0;i<n;i++){
            int rowMin=INT_MAX;
            for(int j=0;j<m;j++){
                rowMin=min(rowMin,matrix[i][j]);
            }
            rowMinMax=max(rowMinMax,rowMin);
        }

        int colMaxMin=INT_MAX;
        for(int j=0;j<m;j++){
            int colMax=INT_MIN;
            for(int i=0;i<n;i++){
                colMax=max(colMax,matrix[i][j]);
            }
            colMaxMin=min(colMaxMin,colMax);
        }
        if(rowMinMax==colMaxMin){
            return {rowMinMax};
        }        
        return {};
    }
};
