class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int>st;
    TreeNode* dfs(TreeNode* node){
        if(node == NULL)return NULL;
        //left
        if(node->left){
            node->left = dfs(node->left);
        }
        //right
        if(node->right){
            node->right = dfs(node->right);
        }
        //abh check karo
        if(st.count(node->val)){
            if(node->left)ans.push_back(node->left);
            if(node->right)ans.push_back(node->right);
            return NULL;
        }
        else{
            return node;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto it : to_delete){
            st.insert(it);
        }
        dfs(root);
        if(st.find(root->val) == st.end()){
            ans.push_back(root);
        }
        return ans;
    }
};