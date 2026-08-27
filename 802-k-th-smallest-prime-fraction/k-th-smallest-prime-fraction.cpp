class Solution {
public:
    typedef long long ll;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i = 0 ;i<n;i++){
            for(int j = n-1 ; j> i ; j--){
                if(pq.size() < k){
                    pq.push({double(arr[i])/arr[j] , {arr[i], arr[j]}});
                }
                else if(pq.top().first > double(arr[i])/arr[j]){
                    pq.pop();
                    pq.push({double(arr[i])/arr[j] , {arr[i], arr[j]}});
                }
            }
        }
        vector<int> ans;
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};