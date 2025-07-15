class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if (n < 3) {
            return false;
        }

        int vowel = 0;
        int consonant = 0;
        for (char& letter : word) {
            if (isalpha(letter) || isdigit(letter)) {
                if (letter == 'a' || letter == 'e' || letter == 'i' ||
                    letter == 'o' || letter == 'u' || letter == 'A' ||
                    letter == 'E' || letter == 'I' || letter == 'O' ||
                    letter == 'U') {
                    vowel++;
                } else if (!isdigit(letter)) {
                    consonant++;
                }
            } else {
                return false;
            }
        }
        cout << vowel << " " << consonant;

        return (vowel >= 1 && consonant >= 1) ? true : false;
    }
};
