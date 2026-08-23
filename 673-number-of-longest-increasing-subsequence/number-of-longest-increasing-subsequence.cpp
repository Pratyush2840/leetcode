class Solution {
public:
    int n;

    pair<int, int> solve(int ind, int prev, vector<int>& nums,vector<vector<pair<int, int>>>& dp) {
        if (ind == n) {
            return {0, 1};
        }
        if (dp[ind][prev + 1].first != -1) {
            return dp[ind][prev + 1];
        }

        pair<int, int> nottake = solve(ind + 1, prev, nums, dp);

        pair<int, int> pick = {0, 0};

        if (prev == -1 || nums[ind] > nums[prev]) {
            pair<int, int> temp =
                solve(ind + 1, ind, nums, dp);

            pick = {1 + temp.first, temp.second};
        }

        pair<int, int> ans;

        if (pick.first > nottake.first) {
            ans = pick;
        }
        else if (nottake.first > pick.first) {
            ans = nottake;
        }
        else {
            ans.first = pick.first;
            ans.second = pick.second + nottake.second;
        }

        return dp[ind][prev + 1] = ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<pair<int, int>>> dp(
            n, vector<pair<int, int>>(n + 1, {-1, -1})
        );

        return solve(0, -1, nums, dp).second;
    }
};