
//APPROACH 1
class Solution {
public:

    bool solve(int ind,string &s1, string &s2, bool &result){
        if(ind==s1.length()){
            if(s2.find(s1)!=string::npos){
                result=true;
            }
            return result;
        }

        for(int i=ind;i<s1.size();i++){
            swap(s1[i],s1[ind]);
            solve(ind+1,s1,s2,result);
            swap(s1[i],s1[ind]);

            if(result==true){
                return result;
            }
        }
        return result;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        bool result =false;

        solve(0,s1,s2,result);

        return result;
        
    }
};


//APPROACH 2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        sort(s1.begin(),s1.end());

        for(int i=0;i<=m-n;i++){
            string substring=s2.substr(i,n);

            sort(substring.begin(),substring.end());

            if(substring==s1){
                return true;
            }
        }
        return false;
    }
};

//APPROACH 3
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);

        for(char ch:s1){
            s1_freq[ch-'a']++;
        }

        int i=0;
        int j=0;
        while(j<m){
            s2_freq[s2[j]-'a']++;
            if(j-i+1>n){
                s2_freq[s2[i]-'a']--;
                i++;
            }

            if(s1_freq==s2_freq){
                return true;
            }
            j++;
        }
        return false;
    }
};
