class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long n = nums.size();

        for (auto& num : nums) {
            pq.push(num);
        }

        long long count = 0;

        while (pq.size() > 1) {

            if(pq.top()>=k){
                break;
            }

            long long mini = pq.top();
            pq.pop();
            long long secMini = pq.top();
            pq.pop();

            long long combo = mini * 2 + secMini;

            count++;
            pq.push(combo);
        }

        return count;
    }
};
