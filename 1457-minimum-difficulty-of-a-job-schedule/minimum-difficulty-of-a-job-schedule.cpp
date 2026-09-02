class Solution {
public:
    int n;
    int dp[305][15][1002];

    int solve(int ind, int day, int maxi_sum,vector<int>& jobDifficulty) {

        if (ind == n) {
            if (day == 0) return 0;
            return 1e9;
        }

        if (day == 0) {
            return 1e9;
        }

        int m = maxi_sum + 1;

        if (dp[ind][day][m] != -1)
            return dp[ind][day][m];

        if (day == 1) {
            int maxi = 0;

            for (int i = ind; i < n; i++) {
                maxi = max(maxi, jobDifficulty[i]);
            }

            return dp[ind][day][m] = maxi;
        }

        int nottake = solve(ind + 1,day,max(maxi_sum, jobDifficulty[ind]),jobDifficulty);

        int take;

        if (maxi_sum == -1) {
            take = jobDifficulty[ind] +solve(ind + 1, day - 1, -1, jobDifficulty);
        }
        else {
            take = max(maxi_sum, jobDifficulty[ind]) +solve(ind + 1, day - 1, -1, jobDifficulty);
        }

        return dp[ind][day][m] = min(nottake, take);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();

        if (n < d)
            return -1;

        memset(dp, -1, sizeof(dp));

        return solve(0, d, -1, jobDifficulty);
    }
};