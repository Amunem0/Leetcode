class Solution {
public:
    int solve(vector<int>nums,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int summation=solve(nums,mid);

            if(summation<=threshold){
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
