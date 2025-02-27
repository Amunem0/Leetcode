class Solution {
public:
    int solve(int secInd,int thirdInd,unordered_map<int,int>&mp,vector<int>&arr){
        int target=arr[thirdInd]-arr[secInd];
        if(mp.count(target) && mp[target]<secInd){ 
            int firstInd=mp[target];
            return solve(firstInd,secInd,mp,arr)+1;
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }

        int maxLen=INT_MIN;

        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=solve(j,k,mp,arr);
                if(len>=3){
                    maxLen=max(maxLen,len);
                }
            }
        }
        return maxLen==INT_MIN ? 0 : maxLen;
    }
};
