class Solution {
public:
    int n;
    int ans = 0 ;
    vector<vector<int>> dp;
    int solve(int ind , int bought_at , vector<int> & prices){
        int temp = 0;
        if(ind >= n){
            if(bought_at == -1){
              return temp;
            }
            return 0;
        }
        if(dp[ind][bought_at+1] != -1)return dp[ind][bought_at+1];
        //buy kar skta
        if(bought_at == -1){
            //bought
            int bought = solve(ind+1 , prices[ind] , prices);
            //not bought
            int not_bought = solve(ind+1 , bought_at , prices);
            return dp[ind][bought_at +1] = max(bought , not_bought);
        }
        //sell kar skta
        else{
            //not sold
            int not_sold =  solve(ind+1 , bought_at,prices);
            //sold
            int sold = prices[ind] - bought_at + solve(ind + 2, -1, prices);

            return dp[ind][bought_at+1] = max(sold, not_sold);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(10002, -1));
        return solve(0 , -1 , prices);
    }
};