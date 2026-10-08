class Solution:
    def solve(self, ind , coins , amount ,dp):
        if amount == 0:
            return 0
        if ind == len(coins)-1:
            if amount % coins[ind] == 0 :
                return amount // coins[ind]
            return int(1e9)
        if(dp[ind][amount] != -1):
            return dp[ind][amount]

        notpick = self.solve(ind+1 , coins , amount ,dp)
        pick = int(1e9)
        if(coins[ind] <= amount):
            pick = 1 + self.solve(ind , coins, amount - coins[ind] ,dp)
        dp[ind][amount] = min(pick,notpick)
        return min(pick,notpick)
    def coinChange(self, coins: list[int], amount: int) -> int:
        dp = [[-1]*(amount+1) for _ in range(len(coins))]
        ans =  self.solve(0 ,coins , amount ,dp)
        if ans >= int(1e9):
            return -1
        return ans