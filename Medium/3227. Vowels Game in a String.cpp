class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int n = s.length();
        int vowel = 0;
        for (auto& ch : s) {
            if (isVowel(ch)) {
                vowel++;
            }
        }
        return vowel > 0? true : false;
    }
};
