class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            int size=j-i+1;
            if(size==3){
                if(nums[i]==0){
                    cout<<i<<endl;
                    nums[i]=!nums[i];
                    nums[i+1]=!nums[i];
                    nums[i+2]=!nums[i];
                    count++;
                }
                i++;
            }
            j++;
        }

        int sum=accumulate(nums.begin(),nums.end(),0);
        cout<<sum<<endl;
        return sum==n?count:-1;
    }
};
