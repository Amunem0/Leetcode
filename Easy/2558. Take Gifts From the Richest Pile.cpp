class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long n=gifts.size();
        priority_queue<long long>maxH;

        for(int i=0;i<n;i++){
            maxH.push(gifts[i]);
        }

        for(int i=0;i<k;i++){
            long long richest=maxH.top();
            maxH.pop();
            long long left=floor(sqrt(richest));
            maxH.push(left);
        }

        long long ans=0;
        while(!maxH.empty()){
            long long elem=maxH.top();
            ans+=elem;
            maxH.pop();
        }

        return ans;
    }
};
