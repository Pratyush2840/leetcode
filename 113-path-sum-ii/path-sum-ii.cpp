class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(TreeNode* root , int sum , int target){
        if(root == NULL){
            return;
        }
        //do
        sum += root->val;
        temp.push_back(root->val);
        //explore kiya left ko 
        solve(root->left , sum , target);
        //explore kiya right ko 
        solve(root->right , sum , target);
        if(root->left == NULL && root->right == NULL){
            if(sum == target)ans.push_back(temp);
        }
        //revert
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return ans;
        
        int sum =0;
        solve(root , sum , targetSum);
        return ans;
    }
};