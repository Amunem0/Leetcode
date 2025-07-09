class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeInt;

        freeInt.push_back(startTime[0]);

        for(int i=1;i<startTime.size();i++){
            freeInt.push_back(startTime[i]-endTime[i-1]);
        }

        freeInt.push_back(eventTime-endTime[endTime.size()-1]);

        int i=0;
        int j=0;
        long long ans=0;
        long long currSum=0;
        int n=freeInt.size();

        while(j<n){
            currSum+=freeInt[j];
            while(i<n && j-i-1>k+1){
                currSum-=freeInt[i];
                i++;
            }

            ans=max(ans,currSum);
            j++;
        }

        return ans;

    }
};
