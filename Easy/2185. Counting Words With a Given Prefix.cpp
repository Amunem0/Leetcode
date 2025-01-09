class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int m=pref.size();

        int count=0;
        for(int i=0;i<n;i++){
            string prefix=words[i].substr(0,m);
            if(pref==prefix){
                count++;
            }
        }
        return count;
    }
};
