class Solution {
public:
    int binarySearch(vector<int>&nums,int y){
        int l=0;
        int r=nums.size()-1;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=y){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int x=nums[i];
            int y=x+2*k;

            int j=binarySearch(nums,y);
            ans=max(j-i+1,ans);
        }
        return ans;
    }
};
