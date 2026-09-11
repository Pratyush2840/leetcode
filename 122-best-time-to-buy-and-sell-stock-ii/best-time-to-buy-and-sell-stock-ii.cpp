class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int day , bool buy , vector<int>& prices){
        if(day >= n){
            return 0;
        }
        if(dp[day][buy] != -1)return dp[day][buy];
        if(buy){
            int bought = solve(day+1 , false , prices) - prices[day];
            int notbought = solve(day+1 , true,prices);
            return dp[day][buy] = max(bought,notbought);
        }
        else{
            int sold = prices[day] + solve(day+1 , true,prices);
            int notsold = solve(day+1 , false , prices);
            return dp[day][buy] = max(sold,notsold);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        bool buy = true;
        dp.assign(n,vector<int>(2,-1));
        return solve(0 , buy , prices);
    }
};