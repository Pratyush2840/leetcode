class Solution {
public:
    int n ;
    int solve(int row,int col , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(row == n-1)return grid[row][col];
        
        if(dp[row][col] != 1e9)return dp[row][col];
        int minval = 1e9;
        for(int i=0 ; i< n; i++){
            int newrow = row + 1;
            int newcol = i;
            if(newrow>=0 && newcol>=0 && newrow < n && newcol<n && newcol != col){
                minval = min(minval , grid[row][col] + solve(newrow,newcol ,grid,dp));
            }
        }
        return dp[row][col] = minval;

    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n  = grid.size();
        int steps = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            steps = min(steps , solve(0,i,grid ,dp));
        }
        return steps;
    }
};