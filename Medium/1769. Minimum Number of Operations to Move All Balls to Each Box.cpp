class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> lrPrefix(n, 0);
        vector<int> rlPrefix(n, 0);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                lrPrefix[i] = lrPrefix[i - 1] + count;
            }
            if (boxes[i] == '1') {
                count++;
            }
        }

        // Right-to-left prefix sum
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                rlPrefix[i] = rlPrefix[i + 1] + count;
            }
            if (boxes[i] == '1') {
                count++;
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = lrPrefix[i] + rlPrefix[i];
        }

        return ans;
    }
};
