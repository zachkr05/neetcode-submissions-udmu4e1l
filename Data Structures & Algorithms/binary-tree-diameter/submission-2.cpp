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


    int dfs(TreeNode* node, int& curr){


        //basecase
        if(!node){
            return 0; // no depth at a node that doesn't exist
        }

        //Search left and right
        int left = dfs(node->left, curr);
        int right = dfs(node->right, curr);

        //Calculate the diameter
        curr = max(curr, left+right); //diameter = max_depth(left) + max_depth(right)

        return 1 + max(left, right);//return the individual depth 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int val = 0;
        dfs(root, val);
        return val;

        
    }
};
