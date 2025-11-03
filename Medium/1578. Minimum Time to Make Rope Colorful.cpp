class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        int prevMax = neededTime[0];

        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1]) {
                prevMax = 0;
            }
            time += min(prevMax, neededTime[i]);
            prevMax = max(prevMax, neededTime[i]);
        }
        return time;
    }
};
