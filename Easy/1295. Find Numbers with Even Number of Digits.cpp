class Solution {
public:
    int numDig(int number){
        int count=0;
        while(number>0){
            number/=10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto &num:nums){
            if(!(numDig(num)&1)){
                ans++;
            }
        }
        return ans;
    }
};
