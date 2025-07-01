class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.length();
        int ans=0;

        char prevChar=word[0];
        for(int i=1;i<n;i++){
            if(word[i]==prevChar){
                ans++;
            }
            prevChar=word[i];
        }
        return ans+1;
    }
};
