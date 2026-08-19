class MyCalendarTwo {
public:
    vector<pair<int,int>> events;

    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {

        events.push_back({startTime, 1});
        events.push_back({endTime, -1});

        sort(events.begin(), events.end());

        int cnt = 0;

        for (auto &it : events) {
            cnt += it.second;

            if (cnt >= 3) {
                for (int i = 0; i < events.size(); i++) {
                    if (events[i] == make_pair(startTime, 1)) {
                        events.erase(events.begin() + i);
                        break;
                    }
                }

                for (int i = 0; i < events.size(); i++) {
                    if (events[i] == make_pair(endTime, -1)) {
                        events.erase(events.begin() + i);
                        break;
                    }
                }

                return false;
            }
        }

        return true;
    }
};