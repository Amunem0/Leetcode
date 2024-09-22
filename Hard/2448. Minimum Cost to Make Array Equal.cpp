class Solution {
public:

    long long findCost(vector<int>&nums,long long mid, vector<int>& cost){
        long long costrq=0;
        for(int i=0;i<nums.size();i++){
            costrq+=abs(nums[i]-mid)*cost[i];
        }
        return costrq;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=INT_MAX;
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());

        while(left<=right){
            long long mid=left+(right-left)/2;

            long long costMid=findCost(nums,mid,cost);
            long long costMidPlusOne=findCost(nums,mid+1,cost);

            ans=min(costMid,costMidPlusOne);

            if(costMid>costMidPlusOne){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
