class Solution {
public:
    int n ,m;
    int solve(int i ,int j ,vector<vector<int>>& grid ,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n ||j>=m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int delrow[] = {-1,0,1};
        int delcol[] = {1,1,1};
        int maxval=0;
        for(int iter=0 ; iter<3;iter++){
            int newrow = i + delrow[iter];
            int newcol = j + delcol[iter];
            if(newrow>=0 && newcol>=0 && newrow < n && newcol<m && grid[newrow][newcol] > grid[i][j]){
                maxval = max(maxval , 1+ solve(newrow,newcol ,grid,dp));
            }
        }
        return dp[i][j]= maxval;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int moves =0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            moves = max(moves , solve(i,0,grid ,dp));
        }
        return moves;
    }
};