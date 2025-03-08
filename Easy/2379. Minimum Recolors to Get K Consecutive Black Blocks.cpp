class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();

        int i=0;
        int j=0;
        int wCount=0;
        int bCount=0;
        int ans=INT_MAX;

        while(j<n){
            if(blocks[j]=='W'){
                wCount++;
            }
            else if(blocks[j]=='B'){
                bCount++;
            }

            if(wCount+bCount==k){
                ans=min(ans,wCount);
                if(blocks[i]=='W'){
                    wCount--;
                }
                else{
                    bCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
