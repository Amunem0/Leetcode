//APPROACH 1
class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int lastSeen[3]={-1,-1,-1};
        int count =0;
        while(i<s.size()){
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]>=0 && lastSeen[1]>=0 && lastSeen[2]>=0){
                count+=min({lastSeen[0],lastSeen[1],lastSeen[2]})+1;
            }
            i++;
        }
        return count;
    }
};


//APPROACH 2
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int n = s.length();

        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n) {
            mp[s[j]]++;
            while (mp.size() == 3) {
                ans += n - j;
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
