class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                int sum = 0;
                for (int j = i + 1; j <= i + k; j++) {
                    sum += code[j % n];
                }
                ans[i] = sum;
            } else {
                int sum = 0;
                for (int j = i - abs(k); j < i; j++) {
                    sum += code[(j + n) % n];
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};
