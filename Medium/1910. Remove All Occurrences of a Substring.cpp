class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=string::npos){
            int startInd=s.find(part);

            s=s.substr(0,startInd)+s.substr(startInd+part.length());
        }
        return s;
    }
};
