class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n =nums.size();
        int ans=0;
        for(int i = 0 ;i < n-2 ; i++){
            int itr = 0;
            if(nums[i+1] - nums[i] == nums[i+2] - nums[i+1]){
                itr=i+3;
                ans++;
                //cout<<"one"<<endl;
                while(itr <n && nums[itr] - nums[itr-1] == nums[i+2] - nums[i+1]){
                    ans++;
                    itr++;
                    //cout<<"two"<<endl;
                }
            }
        }
        return ans;
    }
};