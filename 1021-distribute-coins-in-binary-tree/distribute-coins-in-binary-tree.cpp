class Solution {
public:
    int moves=0;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh = solve( root->left);
        int rh = solve(root->right);
        moves += abs(lh) + abs(rh);
        return (lh+rh+ root->val)-1;
    }
    int distributeCoins(TreeNode* root) {
        int temp = solve(root);
        return moves;
    }
};