class Solution {
public:
    int n,ans=0;
    int m;
    void solve(int i ,int j ,int & temp , vector<vector<int>>& grid){
        if(i<0 || j <0 || i >= n || j >= m || grid[i][j] ==0){
            return;
        }
        //taking it 
        temp += grid[i][j];
        ans = max(ans, temp);
        int temp2 = grid[i][j];
        grid[i][j] =0;
        // call for its adj
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,-1,0,1};
        for(int iter=0;iter<4;iter++){
            int newi = i + delrow[iter];
            int newj = j + delcol[iter];
            solve(newi,newj, temp , grid);
        }
        grid[i][j] = temp2;
        temp -= grid[i][j];
        return;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int temp=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] != 0){
                    solve(i,j,temp,grid);
                }
            }
        }
        return ans;
    }
};