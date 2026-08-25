class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> hash(101, 0);
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        int multiple = k;
        while(multiple <= 100 && hash[multiple] != 0) {
            multiple += k;
        }
        return multiple;
    }
};