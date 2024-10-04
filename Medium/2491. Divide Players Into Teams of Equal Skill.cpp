class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int i=0;
        int j=n-1;
        sort(skill.begin(),skill.end());
        int prevSum=skill[i]+skill[j];
        long long chem=0;

        while(i<j){
            int currSum=skill[i]+skill[j];

            if(currSum!=prevSum){
                return -1;
            }

            chem+=(long long)skill[i]*(long long)skill[j];
            i++;
            j--;
        } 
        return chem;
    }
};
