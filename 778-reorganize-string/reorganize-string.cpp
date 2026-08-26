class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto c : s){
            mp[c]++;
        }
        int sum =0;
        for(auto it : mp){
            pq.push({it.second , it.first});
            sum += it.second;
        }
        string ans = "";
        
        while(!pq.empty()){
            auto [freq , el] = pq.top();
            pq.pop();
            if(!ans.empty() &&  ans.back() == el){
                if (pq.empty()) {
                    return "";
                }
                auto [freq2 , el2] = pq.top();
                pq.pop();
                ans += el2;
                if(freq2 -1 > 0)pq.push({freq2-1 , el2});
                pq.push({freq , el});
            }
            else{
                ans += el;
                if(freq - 1 > 0)pq.push({freq-1, el});
            }
        }
        return ans;
    }
};