class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;

        for (auto& elem : arr) {
            int rem = (elem % k + k) % k; // handling negative elements
            mp[rem]++;
        }

        if(mp[0]%2!=0){
            return false;
        }

        for (int remainder = 1; remainder <= k / 2; remainder++) {
            int counterHalf = k - remainder;

            if (mp[counterHalf] != mp[remainder]) {
                return false;
            }
        }
        return true;
    }
};
