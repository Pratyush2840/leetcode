class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s, string &p) {
        if (i == s.size() && j == p.size())
            return true;

        if (j == p.size())
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = (i < s.size() && 
                     (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            bool notTake = solve(i, j + 2, s, p);
            bool take = match && solve(i + 1, j, s, p);

            return dp[i][j] = take || notTake;
        }

        if (match)
            return dp[i][j] = solve(i + 1, j + 1, s, p);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, s, p);
    }
};