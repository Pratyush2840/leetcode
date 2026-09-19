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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxval=0;
        queue<pair<TreeNode* ,long long>> q;
        q.push({root , 0});
        while(!q.empty()){
            long long size = q.size();
            long long mn = q.front().second;
            vector<long long> temp;
            for(int i = 0 ; i < size; i++){
                auto p = q.front();
                q.pop();
                long long gg = p.second;
                TreeNode* node = p.first;
                gg -= mn;
                temp.push_back(gg);
                if(node->left){
                    q.push({node->left, (2 * gg)});

                }
                if(node->right){
                    q.push({node->right , (2*gg)+1});
                }

                maxval = max(maxval , (temp.back() - temp[0]) +1);


            }
        }
        return (int)maxval;
    }
};