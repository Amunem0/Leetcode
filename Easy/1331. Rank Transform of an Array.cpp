class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> sorted;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sorted.push_back({arr[i], i});
        }

        // Sort based on the values (first element of the pair)
        sort(sorted.begin(), sorted.end());
        cout << endl;

        vector<int> ans(n, 0);
        int rank = 1;
        for (int i = 0; i < n; i++) {
            if (i != 0 && sorted[i].first == sorted[i - 1].first) {
                // If the value is the same as the previous one, assign the same rank
                ans[sorted[i].second] = ans[sorted[i - 1].second];
            } else {
                // If the value is different, assign the current rank and increment the rank
                ans[sorted[i].second] = rank;
                rank++;
            }
        }

        return ans;
    }
};
