class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> mp;
        int n = word.size();
        vector<int> nextConst(n, 0);
        int lastConstInd=n;
        for (int i = n - 1; i >= 0; i--) {
            nextConst[i] = lastConstInd;
            if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' &&
                word[i] != 'o' && word[i] != 'u') {
                lastConstInd = i;
            }
        }

        int i = 0;
        int j = 0;
        int consonants = 0;
        long long ans = 0;
        while (j < n) {
            if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                word[j] == 'o' || word[j] == 'u') {
                mp[word[j]]++;
            } else {
                consonants++;
            }
            while (i<n && consonants > k) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                    word[i] == 'o' || word[i] == 'u') {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0) {
                        mp.erase(word[i]);
                    }
                } else {
                    consonants--;
                }
                i++;
            }
            while (i<n && mp.size() == 5 && consonants == k) {
                int ind = nextConst[j];
                ans += ind - j;
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                    word[i] == 'o' || word[i] == 'u') {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0) {
                        mp.erase(word[i]);
                    }
                } else {
                    consonants--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
