class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            cout << meeting[0] << " " << meeting[1] << endl;
        }

        int freeDays=0;
        int lastEnd=0;

        for(auto &meeting:meetings){
            int start=meeting[0];
            int end=meeting[1];

            if(start>lastEnd+1){
                freeDays+=(start-lastEnd-1);
            }

            lastEnd=max(lastEnd,end);
        }

        if(lastEnd<days){
            freeDays+=days-lastEnd;
        }
        return freeDays;
    }
};
