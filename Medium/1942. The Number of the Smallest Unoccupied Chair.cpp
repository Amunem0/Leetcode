class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<int> endTimes(n, -1);
        
        int targetArrivalTime = times[targetFriend][0];
        
        sort(begin(times), end(times));
        
        for(vector<int> &time : times) {
            int arrival = time[0];
            int depart  = time[1];
            //Find the first unoccupied chair
            for(int i = 0; i<n; i++) {
                if(endTimes[i] <= arrival) {
                    endTimes[i] = depart; //update with current friend depart time
                    
                    if(arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};
