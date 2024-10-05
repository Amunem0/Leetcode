
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
