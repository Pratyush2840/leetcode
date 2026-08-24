class Solution {
public:
    int n;
    int ans = 0;
    void solve(int ind, int k, vector<int>& nums, vector<int>& temp) {
        if (ind == n) {
            if (!temp.empty())
                ans++;
            return;
        }
        solve(ind + 1, k, nums, temp);
        bool valid = true;

        for (int x : temp) {
            if (abs(x - nums[ind]) == k) {
                valid = false;
                break;
            }
        }
        if (valid) {
            temp.push_back(nums[ind]);
            solve(ind + 1, k, nums, temp);
            temp.pop_back();
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        ans = 0;
        vector<int> temp;
        solve(0, k, nums, temp);
        return ans;
    }
};