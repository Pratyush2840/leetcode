class Solution:
    def solve(self ,ind, nums ,dp):
        if(ind >= len(nums)):
            return 0
        if(dp[ind] != -1):
            return dp[ind]
        pick = nums[ind] + self.solve(ind+2 , nums,dp)
        notpick = self.solve(ind+1 , nums,dp)
        dp[ind]= max(pick,notpick)
        return dp[ind]
    def rob(self, nums: list[int]) -> int:
        dp = [-1]*len(nums)
        return self.solve(0, nums ,dp)