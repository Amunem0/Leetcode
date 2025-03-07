class Solution {
public:
    vector<bool> generatePrimes(int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = generatePrimes(right);
        vector<int> primes;

        for (int num = left; num <= right; num++) {
            if (isPrime[num]) {
                primes.push_back(num);
            }
        }

        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> closestPair = {-1, -1};

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primes[i - 1], primes[i]};
            }
        }

        return closestPair;
    }
};
