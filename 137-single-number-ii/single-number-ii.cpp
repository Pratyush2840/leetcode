class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit = 0 ; bit < 32 ; bit++){
            int cnt = 0;
            for(int i = 0 ; i<nums.size() ; i++){
                if(nums[i] & (1<<bit)){
                    cnt++;
                }
            }
            if(cnt %3 != 0){
                ans = ans | (1<<bit);
            }
        }
        return ans;
    }
};