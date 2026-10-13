class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int,int>>q;
        q.push({start , arr[start]});
        int n = arr.size();
        unordered_set<int>st;
        st.insert(start);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            auto ind = it.first;
            auto value = it.second;
            if(value == 0)return true;
            if(ind + value < n && st.count(ind+value) == 0){
               q.push({ind+value , arr[ind+value]});
               st.insert(ind+value); 
            }
            if(ind - value >= 0 && st.count(ind-value) ==0){
                q.push({ind-value , arr[ind-value]});
                st.insert(ind-value);
            }
        }
        return false;
    }
};