class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==']'){
                st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};
