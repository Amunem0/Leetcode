class Solution {
public:
    int bestStartingPoint(string &word, int n) {
        int start = 0, curr = 1;

        while (curr < n) {
            int offset = 0;
            while (curr + offset < n && word[start + offset] == word[curr + offset])
                offset++;

            if (curr + offset < n && word[curr + offset] > word[start + offset]) {
                start = curr;
                curr++;
            } else {
                curr += offset + 1;
            }
        }
        return start;
    }

    string answerString(string word, int numFriends) {
        int n = word.size();

        if (numFriends == 1)
            return word;

        int start = bestStartingPoint(word, n);
        int maxLen = n - (numFriends - 1);
        int takeLen = min(maxLen, n - start);

        return word.substr(start, takeLen);
    }
};
