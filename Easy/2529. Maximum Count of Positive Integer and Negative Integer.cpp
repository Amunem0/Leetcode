class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int negInd=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<0){
                negInd=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        low=0;
        high=n-1;
        int posInd=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            cout<<mid<<endl;
            if(nums[mid]>0){
                posInd=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return max(negInd+1,n-posInd);
    }
};
