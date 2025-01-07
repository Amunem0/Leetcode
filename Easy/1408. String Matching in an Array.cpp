class Solution {
public:
    void computeLPS(string &pat,vector<int>&LPS,int m){
        int len=0;
        LPS[0]=0;
        
        int i=1;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=LPS[len-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
    }
    bool search(string& pat, string& txt) {
        // code here
        int n=txt.length();
        int m=pat.length();
        
        vector<int>ans;
        vector<int>LPS(m,0);
        
        computeLPS(pat,LPS,m);
        
        int i=0;
        int j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            if(j==m){
                // ans.push_back(i-j);
                // j=LPS[j-1];
                return true;
            }
            else if(txt[i]!=pat[j]){
                if(j>0){
                   j=LPS[j-1]; 
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(search(words[i],words[j])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
