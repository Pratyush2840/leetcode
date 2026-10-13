class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for(auto it : nums){
            int num=0;
            while(it>0){
                num += it%10;
                it /=10;
            }
            ans = min(ans,num);
        }
        return ans;
    }
};