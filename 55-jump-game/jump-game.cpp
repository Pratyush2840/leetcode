class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ;j<i;j++){
                if(dp[j] == true && j+nums[j] >= i){
                    dp[i] = 1;
                }
            }
        }
        return dp[n-1];
    }
};