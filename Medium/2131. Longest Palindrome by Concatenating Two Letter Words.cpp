class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int length = 0;

        for (string& word : words) {
            string rev = word;
            swap(rev[0], rev[1]);

            if (freq[rev] > 0) {
                length += 4;
                freq[rev]--;
            } else {
                freq[word]++;
            }
        }

        for (auto& it : freq) {
            string word = it.first;
            int count = it.second;

            if (word[0] == word[1] && count > 0) {
                length += 2;
                break;
            }
        }

        return length;
    }
};
