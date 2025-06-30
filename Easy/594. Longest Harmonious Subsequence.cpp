class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int prevCount = mp.begin()->second, prevelem = mp.begin()->first,
            ans = 0;

        for (auto& elem : mp) {
            if (elem.first == prevelem + 1) {
                if (ans < prevCount + elem.second) {
                    ans = prevCount + elem.second;
                }
            }
            prevelem=elem.first;
            prevCount=elem.second;
        }
        return ans;
    }
};
