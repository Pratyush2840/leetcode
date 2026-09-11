class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q) {
        if(root == NULL)
            return NULL;

        if(root->val == p || root->val == q)
            return root;

        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        if(left != NULL && right != NULL)
            return root;

        if(left != NULL)
            return left;

        return right;
    }
    bool find(TreeNode* root, string &path, int target) {
        if(root == NULL)
            return false;

        if(root->val == target)
            return true;

        path += 'L';

        if(find(root->left, path, target))
            return true;

        path.pop_back();

        path += 'R';

        if(find(root->right, path, target))
            return true;

        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //find lowestcommon ancestor
        TreeNode* temp = lca(root , startValue , destValue);
        string start="";
        string end ="";
        find(temp , start , startValue);
        find(temp, end, destValue);
        
        string ans ="";
        for(auto it : start){
            ans+= 'U';
        }
        for(auto it : end){
            ans+= it;
        }
        return ans;

    }
};