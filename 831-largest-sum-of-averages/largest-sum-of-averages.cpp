class Solution {
public:
    double dp[101][101];
    vector<double> prefix;
    int n;
    double solve(int i, int k) {
        if (k == 1) {
            return (prefix[n] - prefix[i]) / (n - i);
        }

        if (dp[i][k] != -1)
            return dp[i][k];

        double ans = 0;
        for (int j = i; j <= n - k; j++) {

            double avg =
                (prefix[j + 1] - prefix[i]) / (j - i + 1);

            ans = max(ans, avg + solve(j + 1, k - 1));
        }
        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = -1;
        return solve(0, k);
    }
};