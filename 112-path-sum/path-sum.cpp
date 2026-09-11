
class Solution {
public:
    bool solve(TreeNode* root , int sum , int target){
        if(root == NULL){
            return false;
        }
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            return sum == target;
        }
        return solve(root->left , sum  , target) || solve(root->right , sum , target);

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        int sum = 0;
        return solve(root , sum , targetSum);
        
    }
};