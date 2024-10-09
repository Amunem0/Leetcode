class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int minMoves=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else{
                minMoves++;
            }
        }

        minMoves+=st.size();
        return minMoves;
    }
};
