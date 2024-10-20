class Solution {
public:

    char solve(vector<char>&vec,char op){
        if(op=='!'){
            return vec[0]=='t'?'f':'t';
        }

        else if(op=='&'){
            for(int i=0;i<vec.size();i++){
                if(vec[i]=='f'){
                    return 'f';
                }
            }
            return 't';
        }

        else if(op=='|'){
            for(int i=0;i<vec.size();i++){
                if(vec[i]=='t'){
                    return 't';
                }
            }
            return 'f';
        }
        return 's';
    }

    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (expression[i] == ',') {
                continue;
            } 
            
            else if (expression[i] == ')') {
                vector<char> vec;
                while (st.top()  != '(') {
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();

                char op = st.top();
                st.pop();

                st.push(solve(vec,op));
            }

            else{
                st.push(expression[i]);
            }
        }

        return st.top()=='t'? true:false;
    }
};
