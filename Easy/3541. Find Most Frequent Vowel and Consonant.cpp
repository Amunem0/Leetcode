class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
        ){
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }

        int maxVowels=INT_MIN;
        int maxConsonants=INT_MIN;

        for(int i=0;i<26;i++){
            if(isVowel(i+'a')){
                maxVowels=max(maxVowels,freq[i]);
            }
            else{
                maxConsonants=max(maxConsonants,freq[i]);
            }
        }
        return maxVowels+maxConsonants;
    }
};
