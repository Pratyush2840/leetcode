class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> v(nums.size(),0);
        int mini = 1e9;
        for (int i= nums.size()-1 ; i >=0 ; i--){
            mini = min(mini,nums[i]);
            v[i] = mini;
        }
        int maxi = 0;
        for(int i = 0 ;i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
            if(maxi - v[i] <= k)return i;
        }
        return -1;
    }
};