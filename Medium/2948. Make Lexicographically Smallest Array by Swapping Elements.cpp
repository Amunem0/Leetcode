class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> numToGroup;
        unordered_map<int, list<int>> groupToList;

        int currentGroup = 0;
        numToGroup[sortedNums[0]] = currentGroup;
        groupToList[currentGroup].push_back(sortedNums[0]);

        for (int i = 1; i < n; i++) {
            if (abs(sortedNums[i] - sortedNums[i - 1]) > limit) {
                currentGroup++;
            }
            numToGroup[sortedNums[i]] = currentGroup;
            groupToList[currentGroup].push_back(sortedNums[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            result[i] = groupToList[group].front();
            groupToList[group].pop_front();
        }

        return result;
    }
};
