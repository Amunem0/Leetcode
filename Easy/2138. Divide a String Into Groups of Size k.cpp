class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        int size = 0;
        string str = "";

        int remainingChar = (n % k);

        if(remainingChar!=0){
            remainingChar=k-remainingChar;
            s.append(remainingChar,fill);
        }


        for (int i = 0; i < s.length(); i++) {
            if (str.size() == k) {
                ans.push_back(str);
                str = "";
            }
            str += s[i];
        }

        if(!str.empty()){
            ans.push_back(str);
        }
        return ans;
    }
};
