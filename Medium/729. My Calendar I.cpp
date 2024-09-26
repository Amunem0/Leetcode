class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    vector<pair<int,int>>calender;
    bool book(int start, int end) {
        for(int i=0;i<calender.size();i++){
            pair<int,int> curr=calender[i];

            if(!(end<=curr.first || start>=curr.second)){
                return false;
            }
        }

            calender.push_back({start,end});
            return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
