class Solution {
public:
    int f(int i, int prev, int k,
          vector<int>& nums,
          vector<vector<vector<int>>>& dp) {
        if (i == nums.size())
            return 0;
        if (dp[i][prev + 1][k] != -1)
            return dp[i][prev + 1][k];
        int notPick = f(i + 1, prev, k, nums, dp);
        int pick = 0;

        if (prev == -1) {
            pick = 1 + f(i + 1, i, k, nums, dp);
        }
        else {
            if (nums[i] == nums[prev]) {
                pick = 1 + f(i + 1, i, k, nums, dp);
            }
            else if (k > 0) {
                pick = 1 + f(i + 1, i, k - 1, nums, dp);
            }
        }

        return dp[i][prev + 1][k] = max(pick, notPick);
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1,
                vector<int>(k + 1, -1))
        );
        return f(0, -1, k, nums, dp);
    }
};