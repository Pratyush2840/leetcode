class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==0 || i == m-1 || j==0  || j== n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] =1;
                    }
                }
            }
        }
        int delrow[] = { -1,0,1,0};
        int delcol[] = {0 ,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int i = 0 ; i< 4; i++){
                int nrow = row+delrow[i];
                int ncol = col + delcol[i];
                if(nrow<m && nrow >= 0 && ncol < n && ncol >=0 && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] =1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i = 0 ; i< m ; i++){
            for(int j = 0;  j <  n ; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }

};