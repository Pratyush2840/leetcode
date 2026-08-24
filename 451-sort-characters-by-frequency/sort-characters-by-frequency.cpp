class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        map<char ,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        string ans ="";
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            int times = it.first;
            char c = it.second;
            for(int i=0;i<times ; i++){
                ans+=c;
            }
        }
        return ans;
    }
};