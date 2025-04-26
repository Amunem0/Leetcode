class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        int minKPos = -1;
        int maxKPos = -1;
        int notIncluded = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                notIncluded = i;
            }
            if (nums[i] == minK) {
                minKPos = i;
            }
            if (nums[i] == maxK) {
                maxKPos = i;
            }

            int smaller = min(minKPos, maxKPos);
            int numOfArray = smaller - notIncluded;
            ans += (numOfArray < 0) ? 0 : numOfArray;
        }
        return ans;
    }
};
