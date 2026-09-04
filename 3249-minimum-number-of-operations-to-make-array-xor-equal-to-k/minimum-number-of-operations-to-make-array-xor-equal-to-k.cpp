class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int z= k;
        for(int i = 0 ; i < 32; i++){
            int cnt  = 0;
            int target =(z>>i)&1; 
            for(int j = 0 ; j < nums.size() ; j++){
                if((nums[j] >> i ) & 1){
                    cnt++;
                }
            }
            //cnt ood target 1 -> tabh no change
            //cnt even target zero -> tabh no change
            //cnt even target 1 -> tabh change hoga
            //cnt odd tqarget 0 - > tabh change
            if((cnt &1) == 1 && target ==0){
                ans++;
            }
            else if((cnt &1) == 0 && target == 1){
                ans++;
            }
        }
        return ans;
    }
};