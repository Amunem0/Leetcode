class Solution {
public:

    int solve(vector<int>&values,int i,int j,vector<vector<int>>&dp){
        if(j-i+1<3){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            int triangle=values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values,k,j,dp);
            ans=min(ans,triangle);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(values,0,n-1,dp);
    }
};
