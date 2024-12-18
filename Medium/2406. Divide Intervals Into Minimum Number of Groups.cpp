class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        priority_queue<int,vector<int>,greater<int>>pq;

        for(vector<int>& interval:intervals){
            int start=interval[0];
            int end=interval[1];

            if(!pq.empty() && start>pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};
