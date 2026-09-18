class Solution {
public:
   long long ans = 0;
   int MOD = 1e9 +7;
    int solve(TreeNode* root , int total){
        if(root == NULL)return 0;
        int left = solve(root->left,total);
        int right = solve(root->right,total);
        ans = max(ans , (1LL *left * (total-left)));
        ans = max(ans , (1LL *right *(total-right)));

        return left + right + root->val;
    }
    int checksum(TreeNode* root){
        if(root == NULL)return 0;
        int left = checksum(root->left);
        int right = checksum(root->right);
        return left + right + root->val;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL)return 0;
        TreeNode* temp = root;
        int total = checksum(temp);
        solve(root , total);
        return ans % MOD;
    }
};