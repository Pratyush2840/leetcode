class Solution {
public:
    map<int,int> mp;
    int f(int ind , int jump ,vector<int>&stones , vector<vector<int>>& dp){
        if(ind == stones.size() -1)return 1;

        if(dp[ind][jump] != -1)return dp[ind][jump];
        int one =0;
        if(jump >1 && mp.count(stones[ind] + jump -1)){
            one = f(mp[stones[ind] + jump -1] , jump -1 ,stones,dp);
        }
        int same=0;
        if(mp.count(stones[ind] + jump)){
            same = f(mp[stones[ind] + jump] , jump , stones,dp);
        }
        int more =0;
        if(mp.count(stones[ind] + jump +1)){
            more = f(mp[stones[ind] + jump +1] , jump +1 , stones,dp);
        }
        return dp[ind][jump] = one||same||more;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0;i< n ;i++){
            mp[stones[i]] =i;
        }
        if(stones[1] != 1)return false;
        vector<vector<int>> dp(n , vector<int>(20001,-1));
        return f(1 , 1,stones ,dp);
    }
};