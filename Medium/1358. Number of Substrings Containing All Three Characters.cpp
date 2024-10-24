class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int lastSeen[3]={-1,-1,-1};
        int count =0;
        while(i<s.size()){
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]>=0 && lastSeen[1]>=0 && lastSeen[2]>=0){
                count+=min({lastSeen[0],lastSeen[1],lastSeen[2]})+1;
            }
            i++;
        }
        return count;
    }
};
