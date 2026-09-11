class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        bool past = false;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it == NULL)past =true;
            else{
                if(past)return false;
            }
            if(it!= NULL){
                q.push(it->left);
                q.push(it->right);
            }
        } 
        return true;
    }
};