class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        vector<int> height(m, 0);

        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                height[j] += grid[i][j];
            }
        }
        for(int j = 0; j < m; j++) {
            if(height[j] <= n / 2) {
                for(int i = 0; i < n; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int value = 0;
            for(int j = 0; j < m; j++) {
                value = value * 2 + grid[i][j];
            }
            ans += value;
        }
        return ans;
    }
};