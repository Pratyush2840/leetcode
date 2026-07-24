class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        if (image[sr][sc] == color) return image;
        int col = image[0].size();
        vector<vector<int>> ans = image;
        int initial = image[sr][sc];
        ans[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int i = 0 ; i< 4; i++){
                int nrow = row+ delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow<image.size() && ncol>=0 && ncol< image[0].size() && ans[nrow][ncol] == initial){
                    ans[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};