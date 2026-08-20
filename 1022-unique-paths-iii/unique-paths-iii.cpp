class Solution {
public:
    int n , m ;
    int result =0;
    int numOfZero = 0;
    void backtrack(int i,int j,int cnt,vector<vector<int>>& grid){
        if(i<0||j<0||i>=n||j>=m||grid[i][j] == -1)return;
        if(grid[i][j] ==2 && numOfZero == cnt){
            result++;
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int iter=0;iter<4;iter++){
            int newi = i + delrow[iter];
            int newj = j + delcol[iter];
            if(newi >=0 && newj >=0 && newi<n && newj<m && grid[newi][newj] != -1){
                backtrack(newi , newj , cnt + (grid[newi][newj] == 0) , grid);
            }
        }
        grid[i][j] = temp;
        return;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int start_x =0;
        int start_y =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                if(grid[i][j] == 0){
                    numOfZero++;
                }
            }
        }
        int cnt =0;
        backtrack(start_x , start_y , cnt , grid);
        return result;
    }
};