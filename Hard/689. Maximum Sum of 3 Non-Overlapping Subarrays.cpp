class Solution {
public:
    int frontSum(vector<int>&subArraySum,int count,int ind,int k, vector<vector<int>>&dp){
        if(count==0){
            return -1e6;
        }
        if(ind>=subArraySum.size()){
            return -1e6;
        }

        if(dp[ind][count]!=-1){
            return dp[ind][count];
        }

        int take_ind=subArraySum[ind]+frontSum(subArraySum,count-1,ind+k,k,dp);
        int notTake_ind=0+frontSum(subArraySum,count,ind+1,k,dp);

        return dp[ind][count]=max(take_ind,notTake_ind);

    }

    void solve(vector<int>&subArraySum,vector<int>&ans,int k,int ind,int count, vector<vector<int>>&dp){
        if(count==0){
            return;
        }
        if(ind>=subArraySum.size()){
            return;
        }

        int take_ind=subArraySum[ind]+frontSum(subArraySum,count-1,ind+k,k,dp);
        int notTake_ind=0+frontSum(subArraySum,count,ind+1,k,dp);

        if(take_ind>=notTake_ind){
            ans.push_back(ind);
            solve(subArraySum,ans,k,ind+k,count-1,dp);
        }
        else{
            solve(subArraySum,ans,k,ind+1,count,dp);
        }  
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;

        vector<int>subArraySum;
        int windowSum=0;
        while(j<n){
            windowSum+=nums[j];
            if(j-i+1==k){
                subArraySum.push_back(windowSum);
                windowSum-=nums[i];
                i++;
            }
            j++;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(3+1,-1));
        vector<int>ans;
        solve(subArraySum,ans,k,0,3,dp);

        return ans;
    }
};
