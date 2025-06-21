class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int n = word.length();
        for (int i = 0; i < n; i++) {
            char ch = word[i] - 'a';
            freq[ch]++;
        }
        sort(freq.begin(), freq.end());
        int ans = INT_MAX;
        int cumm_del = 0;

        for (int i = 0; i < 26; i++) {
            int deleted = cumm_del;
            for (int j = 25; j > i; j--) {
                if (freq[j] - freq[i] <= k) {
                    break;
                }
                deleted += freq[j] - freq[i] - k;
            }
            ans = min(ans, deleted);
            cumm_del += freq[i];
        }
        return ans;
    }
};
