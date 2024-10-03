class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

        if (totalSum % p == 0) {
            return 0;
        }

        long long target = totalSum % p;

        map<long long, long long> mp;
        mp[0] = -1;

        long long currentSum = 0, minLen = n;

        for (long long i = 0; i < n; i++) {
            currentSum = (currentSum + nums[i]) % p;

            long long needed = (currentSum - target + p) % p;

            if (mp.find(needed) != mp.end()) {
                minLen = min(minLen, i - mp[needed]);
            }

            mp[currentSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};
