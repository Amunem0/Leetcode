class Solution {
public:
    void solve(int ind, string& tiles, string currStr, unordered_set<string>& st, vector<int>& visited) {
        st.insert(currStr);
        if (ind >= tiles.size()) {
            return;
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                currStr.push_back(tiles[i]);
                solve(i, tiles, currStr, st, visited);
                visited[i] = false;
                currStr.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        unordered_set<string> st;
        vector<int> visited(n, false);
        solve(0, tiles, "", st, visited);

        return st.size() - 1;
    }
};
