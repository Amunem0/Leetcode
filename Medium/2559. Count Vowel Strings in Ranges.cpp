class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> countVowels(n, 0);

        for (int i = 0; i < n; i++) {
            string& word = words[i];
            int wordSize = word.size();
            if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||
                 word[0] == 'o' || word[0] == 'u') &&
                (word[wordSize - 1] == 'a' || word[wordSize - 1] == 'e' ||
                 word[wordSize - 1] == 'i' || word[wordSize - 1] == 'o' ||
                 word[wordSize - 1] == 'u')) {
                countVowels[i] = (i > 0 ? countVowels[i - 1] : 0) + 1;
            } else {
                countVowels[i] = (i > 0 ? countVowels[i - 1] : 0);
            }
        }
        vector<int> ans;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            int count = countVowels[end];
            if (start > 0) {
                count = count - countVowels[start - 1];
            }
            ans.push_back(count);
        }
        return ans;
    }
};
