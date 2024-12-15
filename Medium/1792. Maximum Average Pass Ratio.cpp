class Solution {
public:
#define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P> pq; // Max-heap: {delta, index}
        int n = classes.size();
        for (int i = 0; i < n; i++) {
            int passStu = classes[i][0];
            int totalStu = classes[i][1];
            double currPassRatio = (double)(passStu) / (totalStu);
            double newPassRatio = (double)(passStu + 1) / (totalStu + 1);

            double delta = newPassRatio - currPassRatio;
            pq.push({delta, i});
        }
        while (extraStudents--) {
            double currMaxDelta = pq.top().first;
            int maxDeltaInd = pq.top().second;
            pq.pop();

            classes[maxDeltaInd][0]++;
            classes[maxDeltaInd][1]++;

            // now add new delta
            double currPassRatio =
                (double)classes[maxDeltaInd][0] / classes[maxDeltaInd][1];
            double newPassRatio = (double)(classes[maxDeltaInd][0] + 1) /(classes[maxDeltaInd][1] + 1);

            double newDelta = newPassRatio - currPassRatio;

            pq.push({newDelta, maxDeltaInd});
        }

        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }
        return ans / n;
    }
};
