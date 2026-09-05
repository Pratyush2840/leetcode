class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        q.push({0,{entrance[0] , entrance[1]}});
        vis[entrance[0]][entrance[1]] =1;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        while(!q.empty()){
            int length = q.size();
            while(length--){
                auto it = q.front();
                q.pop();
                int step = it.first;
                int row = it.second.first;
                int col = it.second.second;
                vis[row][col] =1;
                for(int i=0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0 && ncol >=0  && nrow<n && ncol<m && vis[nrow][ncol] == 0 && maze[nrow][ncol] != '+'){
                        if(nrow == 0 || ncol == 0 || nrow == n-1 || ncol == m-1){
                            return step +1;
                        }
                        else{
                            q.push({step+1 , {nrow,ncol}});
                            vis[nrow][ncol] = 1;
                        }
                    }
                }
            }   
        }
        return -1;
    }
};