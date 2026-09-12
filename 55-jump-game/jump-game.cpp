class Solution {
public:
    int n ;
    bool solve(int ind , vector<int> & nums , vector<int> & dp){
        if(ind > n)return false;
        if(ind == n-1)return true;
        if(dp[ind] != -1)return dp[ind];

        int jumps = nums[ind];
        for(int i = ind +1 ;i <= ind + jumps ; i++){
            if(solve(i , nums ,dp)){
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n,-1);
        return solve(0 , nums,dp);
    }
};