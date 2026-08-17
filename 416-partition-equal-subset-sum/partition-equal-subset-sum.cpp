class Solution {
public:
    bool f(int ind , int sum , vector<int>& nums , vector<vector<int>> &dp){
        if(sum == 0 )return true;
        if(ind == 0 )return nums[0] == sum;
        if(dp[ind][sum] != -1)return dp[ind][sum];

        bool notpick  = f(ind-1 , sum ,nums ,dp);
        bool pick =false;
        if(nums[ind] <= sum) pick = f(ind-1 , sum - nums[ind] ,nums, dp);
        return dp[ind][sum] = pick||notpick; 

    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }
        if(sum% 2 == 0)sum = sum/2;
        else return false;
        vector<vector<int>> dp(nums.size() , vector<int>(sum+1 , -1));
        return f(nums.size() -1 , sum , nums ,dp);
    }
};