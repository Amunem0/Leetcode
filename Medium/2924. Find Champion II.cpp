class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> weakerMark(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            weakerMark[v]++;
        }

        int countAns = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (weakerMark[i] == 0) {
                ans = i;
                countAns++;
            }
        }
        return countAns != 1 ? -1 : ans;
    }
};
