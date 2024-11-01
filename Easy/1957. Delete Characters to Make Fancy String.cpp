class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        vector<int>indexes(n,-1);
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1] && s[i]==s[i+2]){
                indexes[i]++;
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(indexes[i]==-1){
                ans+=s[i];
            }
        }
        return ans;
    }
};
