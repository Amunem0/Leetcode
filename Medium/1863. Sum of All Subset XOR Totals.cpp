class Solution {
public:
    void solve(vector<int>& nums ,int i,vector<int>&temp,vector<vector<int>>&subsets){
        if(i>=nums.size()){
            subsets.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums,i+1,temp,subsets);
        temp.pop_back();
        solve(nums,i+1,temp,subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        vector<vector<int>>subsets;
        vector<int>temp;
        solve(nums,0,temp,subsets);

        for(auto &subset:subsets){
            int XOR=0;
            for(int i=0;i<subset.size();i++){
                XOR^=subset[i];
            }
            sum+=XOR;
        }

        return sum;
    }
};
