class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> arr;
        for(int i = 0; i < plantTime.size() ; i++){
            arr.push_back({growTime[i] , plantTime[i]});
        }
        sort(arr.rbegin() , arr.rend());
        int plant = 0;
        int ans=0;
        for(auto it : arr){

            int pt = it.second;
            int gt = it.first;
            //cout<<pt<<" "<<gt<<endl;
            plant += pt;
            ans = max(ans , plant + gt); 
        }
        return ans;
        
    }
};