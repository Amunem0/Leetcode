class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int sumOne=0;
        int sumZero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                sumOne++;
            }
        }

        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                sumOne--;
            }
            else{
                sumZero++;
            }

            ans=max(ans,sumOne+sumZero);
        }
        return ans;
    }
};
