class Solution {
public:
    int n ;
    int solve(int row,int col , vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(row == n-1)return matrix[row][col];
        
        if(dp[row][col] != 1e9)return dp[row][col];

        int delrow[] = {1,1,1};
        int delcol[] = {0,1,-1};
        int minval = 1e9;
        for(int i =0;i<3;i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if(newrow>=0 && newcol>=0 && newrow < n && newcol<n){
                minval = min(minval , matrix[row][col] + solve(newrow,newcol ,matrix,dp));
            }
        }
        return dp[row][col] = minval;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n  = matrix.size();
        int steps = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            steps = min(steps , solve(0,i,matrix ,dp));
        }
        return steps;
    }
};