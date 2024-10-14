class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>skiplen;
        string result;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                skiplen.push(result.size());
            }
            else if(s[i]==')'){
                int l=skiplen.top();
                skiplen.pop();
                reverse(result.begin()+l,result.end());
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
