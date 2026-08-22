class Solution {
public:
    int solve(int ind, vector<vector<int>>& books,int shelfWidth, vector<int>& dp) {
        if(ind == books.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int width = 0;
        int height = 0;
        int ans = INT_MAX;
        for(int i = ind; i < books.size(); i++) {
            width += books[i][0];
            if(width > shelfWidth)
                break;
            height = max(height, books[i][1]);
            ans = min(ans,height + solve(i + 1, books, shelfWidth, dp));
        }
        return dp[ind] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1);
        return solve(0, books, shelfWidth, dp);
    }
};