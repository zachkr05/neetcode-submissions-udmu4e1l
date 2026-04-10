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

private:

    std::pair<bool, int>dfs(TreeNode* root){


        //true, 0
        //
        if(!root){
            return std::pair<bool, int>(true, 0);
        }

        std::pair<bool, int> right = dfs(root->right);
        std::pair<bool, int> left = dfs(root->left);

        int diff = std::abs(left.second-right.second);

        if(left.first && right.first && ( diff <= 1 ) ){
            return(std::pair<bool, int>(true, std::max(left.second, right.second)+1));
        } else{
            return std::pair<bool, int>(false, max(left.second, right.second)+1);
        }

    };
public:
    bool isBalanced(TreeNode* root) {
        if (!root){
            return true;
        }
        
        std:pair<bool, int> ans = dfs(root);

        return ans.first;
    }
};
