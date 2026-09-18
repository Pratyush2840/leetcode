/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans =0;
    void dfs(TreeNode* root , string temp){
        if(root == NULL){
            return;
        }
        temp += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ans += stoi(temp);
            return;
        }
        dfs(root->left , temp);
        dfs(root->right , temp);
        return;
    }
    int sumNumbers(TreeNode* root) {
        string temp ="";
        dfs(root , temp);
        return ans;
    }
};