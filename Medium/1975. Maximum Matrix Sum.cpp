class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int countOdd=0;
        long long minElem=LLONG_MAX;
        long long totalSum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    countOdd++;
                }
                minElem=min(minElem,abs(1LL*matrix[i][j]));

                totalSum+=abs(matrix[i][j]);
            }
        }

        if(countOdd%2!=0){
            totalSum=totalSum-2*minElem;
        }
        return totalSum;
    }
};
