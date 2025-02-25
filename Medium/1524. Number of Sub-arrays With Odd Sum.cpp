class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();

        vector<int>prefix(n,0);

        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }

        int ans=0;
        int oddCount=0;
        int evenCount=1;

        for(int i=0;i<n;i++){
            if(prefix[i]%2==0){
                //odd+even=odd;
                ans= (ans+oddCount)%MOD;
                evenCount++;
            }
            else{
                //even+odd=odd;
                ans=(ans+evenCount)%MOD;
                oddCount++;
            }
        }
        return ans;
    }
};
