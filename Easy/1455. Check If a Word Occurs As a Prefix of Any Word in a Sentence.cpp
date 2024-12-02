class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int countWord = 0;
        int j = 0;

        for (int i = 0; i < sentence.size(); i++) {
            if (i == 0 || sentence[i - 1] == ' ') {
                countWord++;
                j = 0;
            }

            if (sentence[i] == searchWord[j]) {
                j++;
                if (j == searchWord.size()) {
                    if (i - j + 1 == 0 || sentence[i - j] == ' ') {
                        return countWord;
                    }
                }
            } else if (sentence[i] != searchWord[j]) {
                j = 0;
            }
        }
        return -1;
    }
};
