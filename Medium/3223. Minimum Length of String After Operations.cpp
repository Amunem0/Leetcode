class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        int ans=0;

        for(char &ch:s){
            freq[ch-'a']++;
        }

        for(char &ch:s){
            if(freq[ch-'a']>=3){
                int remove=(freq[ch-'a']/3)*2;
                freq[ch-'a']-=remove;
                ans+=remove;
            }
        }
        return n-ans;
    }
};
