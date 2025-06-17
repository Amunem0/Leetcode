class Solution {
public:
    long long MOD = 1e9 + 7;

    long long findPow(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % MOD;
                n = n - 1;
            } else {
                x = (x * x) % MOD;
                n = n / 2;
            }
        }
        return ans;
    }

    long long nCr(int n, int r, vector<long long>& fact,
                  vector<long long>& fermatFact) {
        // nCr=n!/((n-r)!*r!)

        return fact[n] * fermatFact[n - r] % MOD * fermatFact[r] % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(n + 1, 1);
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i)%MOD;
        }

        // INVERRSE FACT FERMAT'S LITTLE THEOREM
        vector<long long> fermatFact(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPow(fact[i], MOD - 2);
        }

        long long ans = nCr(n - 1, k, fact, fermatFact);
        ans = (ans * m) % MOD;
        ans = (ans * findPow(m - 1, n - k - 1)) % MOD;

        return ans;
    }
};
