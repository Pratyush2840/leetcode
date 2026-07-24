class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                    vis[i][j] =1;
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();
            for(int i = 0 ; i < 4 ;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0  && nrow < m && ncol>=0 && ncol< n && vis[nrow][ncol]==0 && mat[nrow][ncol] == 1){
                    vis[nrow][ncol] =1;
                    mat[nrow][ncol] = dis +1;
                    q.push({dis +1 ,{nrow,ncol}});
                }
            }
        }
        return mat;
    }
};