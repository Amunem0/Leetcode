class Solution {
public:
    int minChanges(string s) {
        int changes=0;
        int n=s.length();
        for(int i=0;i<n-1;i=i+2){
            if(s[i]!=s[i+1]){
                changes++;
            }
        }
        return changes;
    }
};
