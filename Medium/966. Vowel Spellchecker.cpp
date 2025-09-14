class Solution {
public:
    string toLower(string s){
        string lowerString="";
        for(int i=0;i<s.size();i++){
            lowerString+=tolower(s[i]);
        }
        return lowerString;
    }

    string toStar(string s){
        string changedString=s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o' || s[i]=='u'){
                changedString[i]='*';
            }
        }
        return changedString;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>exactMatch;
        unordered_map<string,string>caseMp;
        unordered_map<string,string>vowelMp;

        for(auto &word:wordlist){
            exactMatch.insert(word);

            string lowerCase=toLower(word);
            if(caseMp.find(lowerCase)==caseMp.end()){
                caseMp[lowerCase]=word;
            }

            string vowelStar=toStar(lowerCase);
            if(vowelMp.find(vowelStar)==vowelMp.end()){
                vowelMp[vowelStar]=word;
            }
        }

        vector<string>ans;
        for(auto &query:queries){
            string checkLowerCase=toLower(query);
            string vowelCheck=toStar(checkLowerCase);
            if(exactMatch.count(query)){
                ans.push_back(query);
            }
            else if(caseMp.find(checkLowerCase)!=caseMp.end()){
                ans.push_back(caseMp[checkLowerCase]);
            }
            else if(vowelMp.find(vowelCheck)!=vowelMp.end()){
                ans.push_back(vowelMp[vowelCheck]);
            }
            else{
                ans.push_back("");
            }
        }
        return ans;
    }
};
