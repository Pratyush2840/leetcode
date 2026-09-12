class Solution {
public:
    int solve(TreeNode* root , int minval, int maxval){
        if(root == NULL){
            return abs(maxval - minval);
        }
        minval = min(minval , root->val);
        maxval = max(maxval , root->val);

        int left = solve(root->left , minval,maxval);
        int right = solve(root->right , minval,maxval);

        return max(left , right);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)return 0;
        int minval =1e9;
        int maxval =0;
        return solve(root , minval , maxval);
    }
};