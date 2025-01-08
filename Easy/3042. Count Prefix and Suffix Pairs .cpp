class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string pattern=words[i];
                string text=words[j];
                
                if(pattern.length()>text.length()){
                    continue;
                }

                string prefix=text.substr(0,pattern.length());
                string suffix=text.substr(text.length()-pattern.length(),pattern.length());

                if(prefix==pattern && suffix==pattern){
                    count++;
                }
            }
        }
        return count;
    }
};
