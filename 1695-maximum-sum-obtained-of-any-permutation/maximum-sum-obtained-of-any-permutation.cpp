class Solution {
public:
    int MOD =1e9 +7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int>diff_arr(n,0);
        for(auto it: requests){
            int l = it[0];
            int r = it[1];
            diff_arr[l] += 1;
            if(r < n-1)
                diff_arr[r+1] -=1; 
        }
        for(int i =1;i< n;i++){
            diff_arr[i] += diff_arr[i-1];
        }
        sort(diff_arr.rbegin() , diff_arr.rend());
        sort(nums.rbegin() , nums.rend());
        int ans=0;
        for(int i=0;i<n;i++){
            ans = (ans+ (1LL *nums[i] * diff_arr[i])%MOD) % MOD;
        }
        return ans;
    }
};