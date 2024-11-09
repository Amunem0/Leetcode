class Solution {
public:
    bool solve(int ind,string s ,vector<string>& wordDict, unordered_set<string>&st, unordered_map<int, bool> &memo){
        if(ind>=s.size()){
            return true;
        }

        if(st.find(s)!=st.end()){
            return true;
        }
        if(memo.find(ind)!=memo.end()){
            return memo[ind];
        }
        for(int i=ind;i<s.size();i++){
            string temp=s.substr(ind,i-ind+1);
            if(st.find(temp)!=st.end() && solve(i+1,s,wordDict,st,memo)){
                return memo[ind]= true;
            }
        }
        return memo[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        unordered_map<int, bool> memo;
        for(auto &word:wordDict){
            st.insert(word);
        }
        return solve(0,s,wordDict,st,memo);
    }
};
