class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int>mp;
        for(int elem:nums){
            mp[elem]++;
        }

        int maxLen=INT_MIN;
        for(int elem:nums){
            int currNum=elem;
            int len=0;

            while(currNum<=sqrt(INT_MAX) && mp.count(currNum*currNum)){
                len++;
                currNum=currNum*currNum;
            }

            maxLen=max(maxLen,len);
        }

        return maxLen+1==1?-1:maxLen+1;
    }
};
