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
    string sortVowels(string s) {
        vector<char>vowels;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=vowels[j];
                j++;
            }
        }
        return s;
    }
};
