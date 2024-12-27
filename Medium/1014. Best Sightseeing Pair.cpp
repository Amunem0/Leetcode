class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int i=0,j=1;
        int maxTillInd=values[0]+0;
        int ans=0;
        for(int j=1;j<n;j++){
            ans=max(ans,maxTillInd+(values[j]-j));
            maxTillInd=max(maxTillInd,values[j]+j);
        }
        return ans;
    }
};
