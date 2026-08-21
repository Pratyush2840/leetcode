class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums){
        int l = 0;
        int r =0;
        for(int i =0 ; i< nums.size() ;i++){
            if(nums[i] > 0 ){
                l=i;
                break;
            }
        }
        for(int i =0 ; i< nums.size() ;i++){
            if(nums[i] < 0 ){
                r=i;
                break;
            }
        }
        vector<int>ans;
        while(l<nums.size() && r<nums.size()){
            ans.push_back(nums[l]);
            l++;
            while(l < nums.size() && nums[l] < 0){
                l++;
            }
            ans.push_back(nums[r]);
            r++;
            while(r< nums.size() && nums[r] > 0){
                r++;
            }
        }
        return ans;
    }
};