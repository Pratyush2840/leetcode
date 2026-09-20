class Solution {
public:
    int n;
    int solve(int ind , int time , vector<int> & satisfaction , vector<vector<int>> & dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][time] != -1)return dp[ind][time];
        int pick = time * satisfaction[ind] + solve(ind+1 , time+1 , satisfaction , dp);
        int notpick = solve(ind+1 , time , satisfaction,dp);
        return dp[ind][time] = max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        n = satisfaction.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        return solve(0 , 1 , satisfaction ,dp);
    }
};