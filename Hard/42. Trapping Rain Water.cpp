class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left_MAX(n);
        vector<int>right_MAX(n);

        left_MAX[0]=height[0];
        right_MAX[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            left_MAX[i]=max(left_MAX[i-1],height[i]);
        }

        for(int i=n-2;i>=0;i--){
            right_MAX[i]=max(right_MAX[i+1],height[i]);
        }
        int ans=0;

        for(int i=0;i<n;i++){
            int h=min( left_MAX[i], right_MAX[i]) - height[i];

            ans+=h;
        }
        return ans;
    }
};
