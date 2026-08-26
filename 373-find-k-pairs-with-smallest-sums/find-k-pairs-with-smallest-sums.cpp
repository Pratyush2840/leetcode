class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<long long , pair<int,int>>>pq;
        for(int i = 0 ; i < nums1.size() ; i++){
            for(int j = 0 ; j < nums2.size() ; j++){
                long long sum =nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum , {nums1[i] , nums2[j]}});
                }
                else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum,{nums1[i] , nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            result.push_back({it.second.first , it.second.second});
        }
        reverse(result.begin() , result.end());
        return result;
    }
};