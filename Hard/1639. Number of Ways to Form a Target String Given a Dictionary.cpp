class Solution {
public:
    int solve(int i, int j, int targetSize, int wordSize,vector<vector<long long>>& freq, string& target, vector<vector<long long>>&dp) {
        if (i == targetSize) {
            return 1;
        }
        if (j == wordSize) {
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int notTake = solve(i, j + 1, targetSize, wordSize, freq, target,dp) % 1000000007;
        int take = freq[target[i] - 'a'][j] * solve(i + 1, j + 1, targetSize, wordSize, freq, target,dp) % 1000000007;

        return dp[i][j]=notTake + take % 1000000007;
    }
    int numWays(vector<string>& words, string target) {
        int targetSize = target.size();
        int wordSize = words[0].size();
        vector<vector<long long>> freqChar(26, vector<long long>(wordSize, 0));

        for (int i = 0; i < wordSize; i++) {
            for (const auto& word : words) {
                char ch = word[i];
                freqChar[ch - 'a'][i]++;
            }
        }

        vector<vector<long long>>dp(targetSize,vector<long long>(wordSize,-1));
        return solve(0, 0, targetSize, wordSize, freqChar, target,dp);
    }
};
