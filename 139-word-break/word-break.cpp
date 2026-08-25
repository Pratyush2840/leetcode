class Solution {
public:
    map<string, int> mp;
    int n;
    bool solve(int ind, string s , vector<int>& dp) {
        if(ind == n) {
            return true;
        }
        if(dp[ind] != -1)return dp[ind];
        string temp = "";
        for(int i = ind; i < n; i++) {
            temp += s[i];
            if(mp.find(temp) != mp.end()) {
                if(dp[ind] = solve(i + 1, s,dp)) {
                    return true;
                }
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto word : wordDict) {
            mp[word]++;
        }
        vector<int>dp(n,-1);
        return solve(0, s ,dp);
    }
};