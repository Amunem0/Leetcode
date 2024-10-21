class Solution {
public:
    int solve(int i, string s, set<string>& st, int currCount, int& maxCount) {
        if (i >= s.length()) {
            maxCount = max(maxCount, currCount);
            return maxCount;
        }

        for (int end = i; end < s.length(); end++) {
            string substring = s.substr(i, end - i + 1);
            if (st.find(substring) != st.end()) {
                continue;
            } else {
                st.insert(substring);
                solve(end + 1, s, st, currCount + 1, maxCount);
                st.erase(substring);
            }
        }
        return maxCount;
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        int maxCount = 0;
        int currCount = 0;
        return solve(0, s, st, currCount, maxCount);
    }
};
