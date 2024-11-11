class Solution {
public:
    void populatePrime(vector<int>& isPrime) {
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < 1000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> isPrime(1000, true);
        populatePrime(isPrime);

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                for (int prime = 2; prime < nums[i]; prime++) {
                    if (isPrime[prime] && nums[i] - prime < nums[i + 1]) {
                        nums[i] -= prime;
                        break;
                    }
                }
            }
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
