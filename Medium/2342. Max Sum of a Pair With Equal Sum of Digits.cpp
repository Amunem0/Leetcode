class Solution {
public:
    int sumdig(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        
        // Pair each number with its sum of digits
        vector<pair<int, int>> digitSumPairs;
        for (int num : nums) {
            digitSumPairs.push_back({sumdig(num), num});
        }

        // Sort pairs based on their digit sum
        sort(digitSumPairs.begin(), digitSumPairs.end());

        int ans = -1;
        for (int i = 1; i < n; i++) {
            if (digitSumPairs[i].first == digitSumPairs[i - 1].first) {
                ans = max(ans, digitSumPairs[i].second + digitSumPairs[i - 1].second);
            }
        }

        return ans;
    }
};
