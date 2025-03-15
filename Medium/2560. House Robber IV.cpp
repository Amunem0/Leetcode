class Solution {
public:
    bool canSatisfy(vector<int>&nums,int kHouses,int maxCapability){
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=maxCapability){
                kHouses--;
                i++;
            }
            if(kHouses==0){
                return true;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSatisfy(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
