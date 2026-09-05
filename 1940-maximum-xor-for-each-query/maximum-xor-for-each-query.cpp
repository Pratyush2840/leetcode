class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int number = (1<<maximumBit) -1;
        int n = nums.size();
        vector<int> result;
        int temp = nums[0];
        for(int i = 1 ; i < n ; i++){
            temp = temp^ nums[i];
        }
        int i = n-1;
        while(i >=0){
            result.push_back((temp ^ number));
            temp = temp ^ nums[i];
            i--;
        }
        return result;
    }
};