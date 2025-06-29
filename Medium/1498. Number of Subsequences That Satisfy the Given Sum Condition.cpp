class Solution {
public:
#define MOD 1000000007
    int power(int a, int b) {
        long long ans = 1;
        long long base=a;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = ans * base % MOD;
                b = b - 1;
            } else {
                base = base * base % MOD;
                b = b / 2;
            }
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left <= right) {

            if (nums[left] + nums[right] <= target) {
                ans =(ans + power(2, right - left)) % MOD;
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
