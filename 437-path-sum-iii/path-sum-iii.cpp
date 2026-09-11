class Solution {
public:
    int ans=0;
    void solve(TreeNode* root , long long sum ,int& tempans, int target){
        if(root == NULL)return;
        sum += root->val;
        if(sum == target){
            tempans++;
        }
        solve(root->left,sum,tempans,target);
        solve(root->right, sum,tempans,target);
    }
    int path(TreeNode* root, int targetSum) {
        long long sum =0;
        int tempans = 0;
        solve(root , sum ,tempans, targetSum);
        return tempans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it){
                ans += path(it,targetSum);
            }
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
        }
        return ans;
    }
};