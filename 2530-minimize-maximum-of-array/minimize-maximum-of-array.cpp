class Solution {
public:
    bool check(long long target, vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > target * (i + 1))
                return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        long long low = 0;
        long long high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, nums)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};