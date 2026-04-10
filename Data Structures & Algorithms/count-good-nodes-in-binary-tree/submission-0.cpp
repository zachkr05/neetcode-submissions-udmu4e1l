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

    int dfs(TreeNode* node, int maxVal){

        if (!node){ // null node
            return 0;
        }

        int res = 0; //clean up later
        if (node->val >= maxVal){
            res = 1;
        }
        int curr_max = max(maxVal, node->val);

        res += dfs(node->right, curr_max);
        res += dfs(node->left, curr_max);
        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
