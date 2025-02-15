class Solution {
public:
    bool isSumDigit(int sq, int num, string squareString, int i, int currSum,
                    vector<vector<int>>& dp) {
        if (i >= squareString.size()) {
            return currSum == num;
        }
        if (currSum > num) {
            return false;
        }

        if (dp[i][currSum] != -1) {
            return dp[i][currSum];
        }

        bool possiblePart = false;
        for (int j = i; j < squareString.size(); j++) {
            string partition = squareString.substr(i, j - i + 1);
            int partitionSum = stoi(partition);

            possiblePart =
                possiblePart || isSumDigit(sq, num, squareString, j + 1,
                                           currSum + partitionSum, dp);

            if (possiblePart == true) {
                return dp[i][currSum] = true;
            }
        }
        return dp[i][currSum] = possiblePart;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            string squareString = to_string(sq);
            vector<vector<int>> dp(squareString.length() + 1,
                                   vector<int>(i + 1, -1));
            if (isSumDigit(sq, i, squareString, 0, 0, dp) == true) {
                ans += i * i;
            }
        }
        return ans;
    }
};
