class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool flag=true;
        int n=sentence.length();
        if(sentence[0]!=sentence[n-1]){
            flag=false;
            return flag;
        }
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]){
                    flag=false;
                    return flag;
                }
            }
        }
        
        return flag;
    }
};
