class Solution {
public:
    int n, m;
    vector<vector<long long>> dp;

    long long solve(int row, int col, vector<vector<int>>& points) {
        if (row == n - 1)
            return points[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        long long maxi = LLONG_MIN;

        for (int newcol = 0; newcol < m; newcol++) {
            long long value = points[row][col] - abs(col - newcol) + solve(row + 1, newcol, points);
            maxi = max(maxi, value);
        }
        return dp[row][col] = maxi;
    }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<long long> dp(m);

        for (int j = 0; j < m; j++) {
            dp[j] = points[0][j];
        }

        for (int i = 1; i < n; i++) {

            vector<long long> left(m);
            vector<long long> right(m);
            vector<long long> cur(m);

            // From left
            left[0] = dp[0];

            for (int j = 1; j < m; j++) {
                left[j] = max(dp[j], left[j - 1] - 1);
            }

            // From right
            right[m - 1] = dp[m - 1];

            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(dp[j], right[j + 1] - 1);
            }

            // Current row
            for (int j = 0; j < m; j++) {
                cur[j] = points[i][j] + max(left[j], right[j]);
            }

            dp = cur;
        }

        return *max_element(dp.begin(), dp.end());
    }
};