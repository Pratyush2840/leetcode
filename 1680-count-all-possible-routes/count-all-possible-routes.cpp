class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][201];
    int solve(int cur, int finish, int fuel, vector<int>& nums) {
        if (dp[cur][fuel] != -1)
            return dp[cur][fuel];
        int ans = (cur == finish);
        for (int i = 0; i < nums.size(); i++) {
            if (i == cur)
                continue;
            int cost = abs(nums[cur] - nums[i]);
            if (fuel >= cost) {
                ans = (ans + solve(i,finish,fuel - cost,nums)) % MOD;
            }
        }
        return dp[cur][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start,int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return solve(start, finish, fuel, locations);
    }
};