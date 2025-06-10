class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int maxOdd=INT_MIN;
        int minEven=INT_MAX;

        for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                maxOdd=max(maxOdd,freq[i]);
            }

            else if(freq[i]%2==0 && freq[i]!=0){
                minEven=min(minEven,freq[i]);
            }
        }

        return maxOdd-minEven;
    }
};
