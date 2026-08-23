class Solution {
public:
    int n;
    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }
        int nottake = solve(ind + 1, prev, nums, dp);
        int pick = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            pick = 1 + solve(ind + 1, ind, nums, dp);
        }
        return dp[ind][prev + 1] = max(nottake, pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }
};