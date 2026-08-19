class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs){
        vector<pair<int,int>> events;
        int n = logs.size();
        for(auto it : logs){
            events.push_back({it[0] , 1});
            events.push_back({it[1] , -1});
        }
        sort(events.begin() , events.end());
        int ans =0;
        int cnt =0;
        int year =0;
        for(int i =0;i<events.size() ;i++){
            if(events[i].second == 1){
                cnt++;
                if(cnt >ans){
                    ans = cnt;
                    year = events[i].first;
                }
            }
            else{
                cnt--;
            }
        }
        return year;
    }
};