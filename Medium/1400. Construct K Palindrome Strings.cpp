class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (k == n) {
            return true;
        }
        if (k > n) {
            return false;
        }

        vector<int> freq(26, 0);

        for(auto &ch:s){
            freq[ch-'a']++;
        }
        
        int oddCount=0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
            }
            if(oddCount > k){
                return false;
            }
        }
        return true;
    }
};
