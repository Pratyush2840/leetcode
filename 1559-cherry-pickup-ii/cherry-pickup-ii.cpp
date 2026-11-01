class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int m=grid.size();
        int n=grid[0].size();

        if(j1<0 || j1>n-1 || j2<0 || j2>n-1){
            return -1e9;
        }
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxx=-1e8;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                int value=0;
                if(j1==j2){
                    value+=grid[i][j1];
                }
                else{
                    value+=grid[i][j1] + grid[i][j2];
                }
                value+=solve(i+1,j1+di,j2+dj,grid,dp);
                maxx=max(maxx,value);
            }
        }
        return dp[i][j1][j2]=maxx;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,0,n-1,grid,dp);
    }
};