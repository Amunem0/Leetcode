class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int usedCount = 0;

        priority_queue<int, vector<int>, greater<int>> activeQueries;
        priority_queue<int> availableQueries;

        sort(queries.begin(), queries.end());

        int queryIndex = 0;

        for (int i = 0; i < n; i++) {
            while (queryIndex < queries.size() && queries[queryIndex][0] == i) {
                availableQueries.push(queries[queryIndex][1]);
                queryIndex++;
            }

            nums[i] -= activeQueries.size();

            while (nums[i] > 0 && !availableQueries.empty() && availableQueries.top() >= i) {
                int endIndex = availableQueries.top();
                availableQueries.pop();

                activeQueries.push(endIndex);
                usedCount++;
                nums[i]--;
            }

            if (nums[i] > 0) {
                return -1;
            }

            while (!activeQueries.empty() && activeQueries.top() == i) {
                activeQueries.pop();
            }
        }

        return queries.size() - usedCount;
    }
};
