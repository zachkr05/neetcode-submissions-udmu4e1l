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

    int dfs(TreeNode* node, int& len){


        if (!node){
            return 0;
        }

        int left = dfs(node->left, len);
        int right = dfs(node->right, len);

        len = max(len, left+right);

        return 1+max(right, left);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int res= 0;
        dfs(root, res);
        return res;
        
    }
};
