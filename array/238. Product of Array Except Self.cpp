class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int product =1;
        int flag= 0;
        for(auto it : nums){
            if(it!=0)product *= it;
            else flag++;
        }
        for(int i= 0 ;i < nums.size() ; i++){
            //dont use chrome 
            if(flag == 1){
                if(nums[i] == 0)ans[i] = product;
                else ans[i] =0;
            }
            else if(flag>1)ans[i]=0;
            else{
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};