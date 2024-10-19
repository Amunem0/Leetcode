class Solution {
public:
    char solve(long long size, int n, int k) {
        if (n == 1) {
            return '0';
        }

        int mid = (size / 2) + 1;

        if (k < mid) {
            return solve(size / 2, n - 1, k);
        } else if (k == mid) {
            return '1';
        }

        else {
            char ch = solve(size / 2, n - 1, size - k + 1);
            return (ch == '0') ? '1' : '0';
        }
    }
    char findKthBit(int n, int k) {
        long long size = pow(2, n) - 1;

        return solve(size, n, k);
    }
};
