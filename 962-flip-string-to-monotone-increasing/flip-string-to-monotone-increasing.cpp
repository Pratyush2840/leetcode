class Solution {
public:
    int solve(int ind ,int prev, int n , string &s ,vector<vector<int>> & dp){
        if(ind == n)return 0;
        int notflip=1e9;
        int flip=1e9;
        if(dp[ind][prev] != -1)return dp[ind][prev];
        if (prev == 0) {
            if (s[ind] == '0') {
                notflip = solve(ind + 1, 0, n, s,dp);
            }
            else {
                notflip = solve(ind + 1, 1, n, s,dp);
            }
            if (s[ind] == '0') {
                flip = 1 + solve(ind + 1, 1, n, s,dp);
            }
            else {
                flip = 1 + solve(ind + 1, 0, n, s,dp);
            }
        }
        else{
            if(s[ind] == '1'){
                notflip = solve(ind+1 , 1 , n,s,dp);
            }
            else{
                flip = 1 + solve(ind+1 , 1 , n , s,dp);
            }
        }
        return dp[ind][prev] =  min(flip , notflip );
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>>dp(n , vector<int>(2,-1));
        return solve(0 , 0,n , s ,dp);
    }
};