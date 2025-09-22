class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        int maxFreq=INT_MIN;
        int ans=0;
        for(int i=0;i<freq.size();i++){
            if(maxFreq<freq[i]){
                ans=freq[i];
                maxFreq=freq[i];
            }
            else if(maxFreq==freq[i]){
                ans+=freq[i];
            }
        }
        return ans;
    }
};
