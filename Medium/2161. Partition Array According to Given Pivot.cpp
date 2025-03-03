class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser;
        vector<int> greater;

        int n = nums.size();
        int countPivot = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                lesser.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                countPivot++;
            } else {
                greater.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < lesser.size(); i++) {
            ans.push_back(lesser[i]);
        }
        while (countPivot--) {
            ans.push_back(pivot);
        }
        for (int i = 0; i < greater.size(); i++) {
            ans.push_back(greater[i]);
        }
        return ans;
    }
};
