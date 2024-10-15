class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int zero=0;
        int one=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
                ans+=one;
            }
            else{
                one++;
            }
        }
        return ans;
    }
};
