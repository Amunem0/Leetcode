class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> diffIndices;

        // Find mismatch positions
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        if (diffIndices.empty())
            return true;

        if (diffIndices.size() == 2) {
            int i = diffIndices[0], j = diffIndices[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }

        return false;
    }
};
