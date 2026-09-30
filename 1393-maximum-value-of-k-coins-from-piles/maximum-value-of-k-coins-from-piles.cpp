class Solution {
public:
    int steps = 0;
    int solve(vector<vector<int>> & piles , int x , int k ,vector<vector<int>>& dp){
        if(k == 0)return 0;
        if(x == piles.size()){
            return 0;
        }
        if(dp[x][k] != -1)return dp[x][k];
        
        int nottake = solve(piles , x+1 , k ,dp);
        int sum = 0;
        int take= 0;
        for(int i = 0 ; i < piles[x].size() && i < k; i++){
            int money = 0;
            if( k - i +1 > 0){
                sum += piles[x][i];
                money = sum + solve(piles , x+1 , k - (i +1) , dp);
            }
            take = max(take , money);
        }
        return dp[x][k] =  max(nottake , take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        steps = k;
        vector<vector<int>> dp(n+1 , vector<int>(k+1 , -1));
        return solve(piles , 0 , k ,dp);
    }
};