class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for (auto& currFolder : folder) {
            bool isSubfolder = false;

            string temp = currFolder;
            while (!temp.empty()) {
                int positionOfSlash = temp.find_last_of('/');

                temp = temp.substr(0, positionOfSlash);

                if (st.find(temp) != st.end()) {
                    isSubfolder = true;
                    break;
                }
            }

            if (!isSubfolder) {
                ans.push_back(currFolder);
            }
        }

        return ans;
    }
};
