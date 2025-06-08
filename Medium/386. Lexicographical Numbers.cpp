class Solution {
public:
    void solve(int currNum,int n,vector<int>&ans){
        if(currNum>n){
            return;
        }

        ans.push_back(currNum);
        for(int appendNum=0;appendNum<=9;appendNum++){
            int newNum=(currNum*10)+appendNum;

            if(newNum>n){
                return;
            }
            solve(newNum,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};
