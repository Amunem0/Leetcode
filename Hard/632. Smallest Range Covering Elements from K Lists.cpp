class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<int> vec(n, 0);

        vector<int> resultRange = {-1000000, 1000000};

        while (true) {
            int minElem = INT_MAX;
            int maxElem = INT_MIN;
            int minElemInd = 0;

            for (int i = 0; i < n; i++) {
                int listInd = i;
                int elemInd = vec[i];
                int elem = nums[listInd][elemInd];

                if (elem < minElem) {
                    minElem = elem;
                    minElemInd = listInd;
                }

                maxElem = max(maxElem, elem);
            }

            if (maxElem - minElem < resultRange[1] - resultRange[0]) {
                resultRange[0] = minElem;
                resultRange[1] = maxElem;
            }

            int nextInd = vec[minElemInd] + 1;
            if (nextInd >= nums[minElemInd].size()) {
                break;
            }
            vec[minElemInd] = nextInd;
        }
        return resultRange;
    }
};
