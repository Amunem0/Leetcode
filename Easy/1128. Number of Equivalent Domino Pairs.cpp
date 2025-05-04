class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        map<pair<int,int>,int>mp;
        int ans=0;
        for(auto &dominoe:dominoes){
            if(dominoe[0]>dominoe[1]){
                swap(dominoe[0],dominoe[1]);
            }
            mp[{dominoe[0],dominoe[1]}]++;
        }

        for(auto &it:mp){
            ans+=it.second*(it.second-1)/2;  //for pair freqC2;
        }
        return ans;
    }
};
