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
    TreeNode* invertTree(TreeNode* root) {
        
        //Define the base case for the recursive func
        if (root == nullptr){
            return nullptr; 
        }

        //Swap the right and left of the tree
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        //Recursively swap nodes 
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
