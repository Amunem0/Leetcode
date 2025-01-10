class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<int> freq2(26, 0);
        for (auto& word : words2) {
            vector<int> temp(26, 0);
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                temp[ch - 'a']++;

                freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']);
            }
        }

        vector<string> ans;

        for (auto word : words1) {
            vector<int> freq1(26, 0);
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                freq1[ch - 'a']++;
            }

            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq1[i] < freq2[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
