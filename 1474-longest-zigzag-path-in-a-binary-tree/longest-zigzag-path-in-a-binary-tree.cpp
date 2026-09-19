class Solution {
public:
    int ans =0;
    int solve(TreeNode* root , int dir ,int cnt){
        if(root == NULL)return 0;
        int cont ;
        int newone;
        if(dir == 0){
            cont = solve(root->right , 1 , cnt+1);
            newone = solve(root->left , 0 , 1);
        }
        if(dir ==1){
            cont = solve(root->left , 0 , cnt+1);
            newone = solve(root->right , 1 , 1);
        }
        ans = max(ans , cnt);
        return max(cont , newone);

    }
    int longestZigZag(TreeNode* root) {
        solve(root->left , 0 , 1);
        solve(root->right , 1 , 1);
        return ans;
    }
};