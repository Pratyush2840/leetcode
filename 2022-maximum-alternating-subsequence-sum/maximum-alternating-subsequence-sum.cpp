class Solution {
public:
    int n;
    // long long solve(int idx, vector<int>& nums, bool iseven) {
    //     if(idx >= n) {
    //         return 0;
    //     }
    //     if(dp[idx][iseven] != -1)
    //         return t[idx][iseven];
    //     long long skip = solve(idx+1, nums, iseven);
    //     long long val = nums[idx];
    //     if(iseven == false) {
    //         val = -val;
    //     }
    //     long long take = solve(idx+1, nums, !iseven) + val;
    //     return dp[idx][iseven] = max(skip, take);
    // }
    long long maxAlternatingSum(vector<int>& nums) {
         n = nums.size();
        vector<vector<long>> dp(n, vector<long>(2, 0));

        dp[0][0] = max(-nums[0], 0);
        dp[0][1] = max(nums[0], 0);
            
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][1] - nums[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + nums[i], dp[i-1][1]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};