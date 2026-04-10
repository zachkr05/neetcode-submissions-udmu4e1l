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

    int dfs(TreeNode* root, int &length){

        if (!root){
            return 0;
        }


        int right = dfs(root->right, length);
        int left = dfs(root->left, length);
        length = max(length, left+right);

        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int res = 0;
        //recursive dfs
        dfs(root, res);
        return res;

    }
};
