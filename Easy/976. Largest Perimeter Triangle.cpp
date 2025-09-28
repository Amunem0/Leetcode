class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }

        sort(nums.begin(),nums.end());

        for(int i=n-1;i>=2;i--){
            int a=nums[i];
            int b=nums[i-1];
            int c=nums[i-2];

            if(a+b>c && b+c>a && c+a>b){
                return a+b+c;
            }
        }
        return 0;
    }
};
