class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n & 1) {
            return false;
        }

        stack<int>open;
        stack<int>openClose;

        for(int i=0;i<n;i++){
            if(s[i]=='(' && locked[i]=='1'){
                open.push(i);
            }
            else if(s[i]==')' && locked[i]=='1'){
                if(!open.empty()){
                    open.pop();
                }
                else if(!openClose.empty()){
                    openClose.pop();
                }
                else{
                    return false;
                }
            }

            else if(locked[i]=='0'){
                openClose.push(i);
            }
        }
        
        // Balancing remaining open parentheses with openClose stack
        while (!open.empty() && !openClose.empty()) {
            if (open.top() < openClose.top()) {
                open.pop();
                openClose.pop();
            } else {
                break;
            }
        }

        return open.empty();
    }
};
