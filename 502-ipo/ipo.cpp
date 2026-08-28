class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        int n = profits.size();
        for(int i = 0 ; i < n ; i++){
            arr.push_back({capital[i] , profits[i]});
        }
        sort(arr.begin() , arr.end());
        priority_queue<pair<int,int>> pq;
        int i =0;
        int ans =0;
        while(k >0){
            while(i < n && arr[i].first <= w){
                pq.push({arr[i].second , arr[i].first});
                i++;
            }
            if(pq.empty())
                break;
            auto it = pq.top();
            pq.pop();
            ans += it.first;
            k--;
            w += it.first;
        }
        return w;

    }
};