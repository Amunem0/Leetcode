class Solution {
public:
    int Count(long curr,long next,long n){
        long countNum=0;
        while(curr<=n){
            countNum+=next-curr;

            curr*=10;
            next*=10;

            next=min(next,n+1);
        }
        return countNum;
    }
    int findKthNumber(int n, int k) {
        long curr=1;
        k--;
        while(k>0){
            int count = Count(curr,curr+1,n);
            if(count<=k){
                curr++;
                k-=count;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
