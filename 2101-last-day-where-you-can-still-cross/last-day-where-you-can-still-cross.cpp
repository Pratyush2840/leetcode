class Solution {
public:
    int delcol[4] = {0, 1, -1, 0};
    int delrow[4] = {1, 0, 0, -1};

    bool dfs(int r, int c, vector<vector<int>>& temp, vector<vector<int>>& vis, int row, int col) {
        if (r == row - 1) return true;

        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int newrow = r + delrow[i];
            int newcol = c + delcol[i];
            if (newrow >= 0 && newrow < row &&newcol >= 0 && newcol < col && temp[newrow][newcol] == 0 && vis[newrow][newcol] == 0) {
                if (dfs(newrow, newcol, temp, vis, row, col))return true;
            }
        }
        return false;
    }

    bool solve(int ind, vector<vector<int>>& cells, int row, int col) {
        vector<vector<int>> temp(row, vector<int>(col, 0));

        for (int i = 0; i <= ind; i++) {
            temp[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++) {
            if (temp[0][j] == 0) {
                if (dfs(0, j, temp, vis, row, col))return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0;
        int high = cells.size() - 1;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (solve(mid, cells, row, col)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};