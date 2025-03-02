class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        vector<int>countArr(1001,0);

        for(auto &num1:nums1){
            int id=num1[0];
            int val=num1[1];
            countArr[id]+=val;
        }
        for(auto &num2:nums2){
            int id=num2[0];
            int val=num2[1];
            countArr[id]+=val;
        }

        vector<vector<int>>ans;

        for(int i=0;i<countArr.size();i++){
            if(countArr[i]!=0){
                ans.push_back({i,countArr[i]});
            }
        }
        return ans;
    }
};
