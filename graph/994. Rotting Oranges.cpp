class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows , vector<int> (cols,0));
        vector<vector<int>> ans;
        ans= grid;
        queue<pair<int,pair<int,int>>> q;
        int fresh=0;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 2){
                    q.push({0 ,{i,j}});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int delrow[] ={-1,0,1,0};
        int delcol[]= {0,1,0,-1};
        int finaltime = 0;
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int time = q.front().first; 
            q.pop();
            vis[row][col] =1;

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow < rows && ncol>=0 && ncol < cols && vis[nrow][ncol] == 0 && ans[nrow][ncol] == 1){
                    vis[nrow][ncol] =1;
                    ans[nrow][ncol] = 2;
                    fresh--;
                    q.push({time +1 , {nrow,ncol}});
                    finaltime = max(finaltime , time + 1);
                }
            }
        }
        if(fresh != 0)return -1;
        return finaltime;
    }
};