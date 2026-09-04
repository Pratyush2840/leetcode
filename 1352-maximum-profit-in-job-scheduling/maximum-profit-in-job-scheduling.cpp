class Solution {
public:
    int n;
    int solve(int ind, vector<vector<int>>& arr, vector<int>& dp) {
        if(ind == n)return 0;

        if(dp[ind] != -1)
            return dp[ind];
            
        // not pick
        int notpick = solve(ind + 1, arr, dp);
        // pick
        int next = lower_bound(arr.begin() + ind + 1,arr.end(),vector<int>{arr[ind][1], 0, 0}) - arr.begin();
        int pick = arr[ind][2] + solve(next, arr, dp);
        return dp[ind] = max(pick, notpick);
    }

    int jobScheduling(vector<int>& startTime,vector<int>& endTime,vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({ startTime[i],endTime[i],profit[i]});
        }
        sort(arr.begin(), arr.end());
        vector<int> dp(n, -1);
        return solve(0, arr, dp);
    }
};