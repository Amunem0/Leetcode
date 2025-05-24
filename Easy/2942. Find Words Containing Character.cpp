class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int ind=0;
        for(auto &word:words){
            int m=word.size();
            for(int i=0;i<m;i++){
                if(word[i]==x){
                    ans.push_back(ind);
                    break;
                }
            }
            ind++;
        }
        return ans;
    }
};
