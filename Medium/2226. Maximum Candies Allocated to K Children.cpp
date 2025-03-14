class Solution {
public:
    bool canSatisfy(vector<int>&candies, long long k,int minCandies){
        long long count=0;
        for(int i=0;i<candies.size();i++){
            count+=(candies[i]/minCandies);
            if(count>=k){
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(canSatisfy(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
