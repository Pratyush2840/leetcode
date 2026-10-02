class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0;
        int cnt = 0;
        int ans = 0;
        for(int right = 0 ; right < nums.size() ; right++){
            if(nums[right] == 1){
                ans = max(ans , right - left +1);
                continue;
            }
            else if(nums[right] == 0 && cnt < k){
                cnt++;
                ans = max(ans , right - left +1);
                continue;
            }
            else if(nums[right] == 0 && cnt == k){
                while(nums[left] == 1){
                    left++;
                }
                left++;
            }
            ans = max(ans , right - left +1);
        }
        return ans;
    }
};