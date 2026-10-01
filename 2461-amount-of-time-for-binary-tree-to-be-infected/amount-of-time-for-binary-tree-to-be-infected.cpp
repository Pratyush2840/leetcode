class Solution {
public:
    map<TreeNode*, bool> vis;
    int findheight(TreeNode* root ,map<TreeNode*,vector<TreeNode*>>& adj ){
        vis[root] = true;
        int height = 0;
        for(auto node : adj[root]){
            if(!vis[node]){
                height = max(height , 1 + findheight(node , adj));
            }
        }
        return height;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,vector<TreeNode*>> adj;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* sp = new TreeNode();
        while(!q.empty()){
            int len = q.size();
            for(int i = 0 ; i < len ; i++){
                auto node = q.front();
                if(node->val == start){
                    sp = node;
                }
                q.pop();
                if(node->left){
                    adj[node].push_back(node->left);
                    adj[node->left].push_back(node);
                    q.push(node->left);
                }
                if(node->right){
                    adj[node].push_back(node->right);
                    adj[node->right].push_back(node);
                    q.push(node->right);
                }
            }
        }
        return findheight(sp , adj);
    }
};