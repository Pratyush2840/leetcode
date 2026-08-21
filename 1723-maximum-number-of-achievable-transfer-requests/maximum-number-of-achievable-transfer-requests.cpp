class Solution {
public:
    int ans = 0;

    void solve(int ind, int count, vector<int>& temp,
               vector<vector<int>>& requests) {
        if(ind == requests.size()) {
            bool valid = true;
            for(int x : temp) {
                if(x != 0) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                ans = max(ans, count);
            }
            return;
        }
        auto it = requests[ind];
        temp[it[0]]++;
        temp[it[1]]--;
        solve(ind + 1, count + 1, temp, requests);
        temp[it[0]]--;
        temp[it[1]]++;
        solve(ind + 1, count, temp, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> temp(n, 0);
        solve(0, 0, temp, requests);
        return ans;
    }
};