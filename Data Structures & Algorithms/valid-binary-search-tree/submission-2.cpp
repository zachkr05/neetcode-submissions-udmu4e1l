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
bool dfs(TreeNode* root, long long low, long long high){

    if(!root){
        return true;
    }

    if(root->val <= low || root->val >= high){ return false; }

    bool left = dfs(root->left, low, root->val); //left subtree needs to be between low and currnode
    bool right = dfs(root->right, root->val, high);

    return left && right;

}
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
