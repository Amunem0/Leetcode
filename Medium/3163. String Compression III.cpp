class Solution {
public:
    string compressedString(string word) {
        int n=word.length();
        string ans="";
        for(int i=0;i<n;i++){
            int count=0;
            char ch=word[i];
            while(count<9 && i<n && word[i]==ch){
                count++;
                i++;
            }
            i--;
            ans+=to_string(count)+ch;
        }
        return ans;
    }
};
