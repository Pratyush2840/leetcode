//16/07/2026
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mi = 0;
        vector<int> prefixgcd;
        for(int i = 0 ; i < n ; i++){
            mi = max(mi,nums[i]);
            prefixgcd.push_back(gcd(mi,nums[i]));
        }
       sort(prefixgcd.begin() , prefixgcd.end());
       long long ans =0 ;
       for(int i = 0 ;  i < n/2 ; i++){
            ans+= gcd(prefixgcd[i] , prefixgcd[n-1-i]);
       }
       return ans;
    }
};