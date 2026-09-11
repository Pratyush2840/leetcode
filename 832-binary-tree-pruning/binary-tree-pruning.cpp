class Solution {
public:
    bool isonePresent(TreeNode* node){
        if(node == NULL){
            return false;
        }
        if(node->val == 1)return true;
        return isonePresent(node->left) || isonePresent(node->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)return NULL;

        if(!isonePresent(root->left)){
            root->left = NULL;
        }
        if(!isonePresent(root->right)){
            root->right = NULL;
        }
        pruneTree(root->left);
        pruneTree(root->right);

        if(root->val == 0 && root->left == NULL && root->right == NULL)return NULL;
        return root;
    }
};