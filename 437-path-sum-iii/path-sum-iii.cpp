class Solution {
public:
    unordered_map<long long, int> mp;
    int solve(TreeNode* root, long long sum, int target) {
        if (root == NULL)
            return 0;
        sum += root->val;
        int ans = 0;
        if (mp.count(sum - target))
            ans += mp[sum - target];
        if (sum == target)
            ans++;
        mp[sum]++;
        ans += solve(root->left, sum, target);
        ans += solve(root->right, sum, target);
        mp[sum]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp.clear();
        return solve(root, 0, targetSum);
    }
};