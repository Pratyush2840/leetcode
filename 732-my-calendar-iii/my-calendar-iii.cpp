class MyCalendarThree {
public:
    vector<pair<int,int>> events;
    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        events.push_back({startTime , 1});
        events.push_back({endTime , -1});
        sort(events.begin() , events.end());
        int cnt =0;
        int ans =0;
        for(auto it : events){
            cnt += it.second;
            ans = max(ans , cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */