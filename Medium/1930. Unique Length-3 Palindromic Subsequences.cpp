class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});

        for (int i = 0; i < n; i++) {
            int ch = s[i];
            int index = ch - 'a';
            if (indices[index].first == -1) {
                indices[index].first = i;
            }
            indices[index].second = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int left_ind = indices[i].first;
            int right_ind = indices[i].second;

            unordered_set<char> st;
            for (int middle = left_ind + 1; middle <= right_ind - 1; middle++) {
                st.insert(s[middle]);
            }

            ans += st.size();
        }
        return ans;
    }
};
