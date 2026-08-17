class Solution {
public:
    int MOD = 1e9 + 7;
    int f(int n ,int prev_absent , int prev_late , vector<vector<vector<int>>>&dp){
        if(n==0)return 1;
        
        int absent =0;
        if(dp[n][prev_absent][prev_late] != -1)return dp[n][prev_absent][prev_late];
        if(prev_absent == 0){
            absent = f(n-1 , 1,0 ,dp);
        }
        int late =0;
        if(prev_late <2){
            late = f(n-1,prev_absent,prev_late+1,dp);
        }
        int present = f(n-1,prev_absent,0,dp);
        return dp[n][prev_absent][prev_late] = ((absent+late)%MOD +present) % MOD;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1 ,vector<vector<int>>(3,vector<int>(4,-1)));
        return f(n,0,0,dp);
    }
};