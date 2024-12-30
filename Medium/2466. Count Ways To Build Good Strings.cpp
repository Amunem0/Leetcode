class Solution {
public:
    int MOD=1000000007;
    int solve(int low,int high,int zero,int one,int currLen,vector<int>&dp){
        if(currLen>high){
            return 0;
        }

        if(dp[currLen]!=-1){
            return dp[currLen];
        }
        int count=0;
        if(currLen>=low && currLen<=high){
            count=1;
        }
        
        int takeZero=solve(low,high,zero,one,currLen+zero,dp);
        int takeOne=solve(low,high,zero,one,currLen+one,dp);
        return dp[currLen]=(count+takeZero+takeOne)%MOD;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return solve(low,high,zero,one,0,dp);
    }
};
