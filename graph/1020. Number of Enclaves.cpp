class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        queue<pair<int,int>>q;
        for(int i = 0 ; i < m ; i++) { 
            for(int  j = 0 ; j < n ; j++){
                if(i == 0 ||i == m-1 || j == 0 || j == n-1){
                    if(grid[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it  = q.front();q.pop();
            int row = it.first;
            int col = it.second;
            for(int i = 0 ; i < 4 ; i++){
                int nrow= row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol >=0 && nrow<m && ncol<n && vis[nrow][ncol] ==0 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        } 
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};