class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;

        int n=nums.size();

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        long long score=0;

        while(k--){
            int maxElem=pq.top();
            pq.pop();

            score+=maxElem;
            maxElem=ceil(maxElem/3.0);
            pq.push(maxElem);
        }

        return score;
    }
};
