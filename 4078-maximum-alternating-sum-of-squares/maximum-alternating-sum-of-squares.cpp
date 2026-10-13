class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            if(nums[i] <0){
                nums[i] *= -1;
            }
        }
        long long ans =0;
        sort(nums.begin() , nums.end());
        int neg = n/2;
        for(int i = 0 ;i < n ; i++){
            if(i < neg){
                ans -= nums[i] * nums[i];
            }
            else{
                ans += nums[i] * nums[i];
            }
        }
        return ans;
    }
};