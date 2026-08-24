class Solution {
public:
    int n;
    int t[100001];

    int solve(int i, vector<int>& prefixSum) {
        if(i == n-1) {
            return prefixSum[n-1];
        }

        if(t[i] != -1)
            return t[i];

        int skip = solve(i+1, prefixSum);
        int take = prefixSum[i] - skip;


        return t[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        memset(t, -1, sizeof(t));

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        

        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }

        return solve(1, prefixSum); 
    }
};