class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int ans=0;
        long long powVal=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                ans++;
            }
            else{
                long long val=(s[i]-'0')*powVal;
                if(k>=val){
                    ans++;
                    k-=val;
                }
            }
            if(powVal<=k){
                powVal*=2;
            }    
        }
        return ans;
    }
};
