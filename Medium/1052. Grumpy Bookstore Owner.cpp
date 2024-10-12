class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int currUnsatisfied=0;
        int maxUnsatisfied=INT_MIN;

        for(int i=0;i<minutes;i++){
            currUnsatisfied+=customers[i]*grumpy[i];           
        }
        maxUnsatisfied=currUnsatisfied;

        int i=0;
        int j=minutes;
        while(j<n){
            currUnsatisfied+=customers[j]*grumpy[j];
            currUnsatisfied-=customers[i]*grumpy[i];
            maxUnsatisfied=max(maxUnsatisfied,currUnsatisfied);
            i++;
            j++;
        }
        int totalSatisfied=maxUnsatisfied;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                totalSatisfied+=customers[i];
            }
        }
        return totalSatisfied;
    }
};
