class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        int i = 25;
        string ans;
        while (i >= 0) {
            if (freq[i] == 0) {
                i--;
                continue;
            }
            char ch = 'a' + i;
            int charFreq = min(freq[i], repeatLimit);

            ans.append(charFreq, ch);
            freq[i] -= charFreq;
            if (freq[i] > 0) {
                int j = i - 1;
                while (j >= 0 && freq[j] == 0) {
                    j--;
                }
                if (j < 0) {
                    break;
                }
                ans.push_back('a' + j);
                freq[j]--;
            }
        }
        return ans;
    }
};
