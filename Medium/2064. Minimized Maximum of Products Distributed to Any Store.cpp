class Solution {
public:
    bool possibleToDistribute(int mid,vector<int>&quantities,int n){
        for(int &quantity:quantities){
            n -= (quantity + mid - 1) / mid;
            if(n<0){
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left=1;
        int right=*max_element(quantities.begin(),quantities.end());
        int ans=0;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(possibleToDistribute(mid,quantities,n)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;


    }
};
