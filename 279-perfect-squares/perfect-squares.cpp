class Solution {
public:
    int f(int n ,vector<int>&dp){
        if(n==1)return 1;
        if(n==0)return 0;
        int i=1;
        int z=1e9;
        if(dp[n]  != -1)return dp[n];
        while((i * i )<= n){
            int next = 1 + f(n - (i*i) , dp);
            z= min(z,next);
            i++;
        }
        return dp[n] = z;
        
    }
    int numSquares(int n) {
        vector<int> dp(n+1 , -1);
        return f(n ,dp);
    }
};