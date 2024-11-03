class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()){
            return false;
        }
        
        if((s+s).find(goal)==string::npos){
            return false;
        }
        return true;
    }
};
