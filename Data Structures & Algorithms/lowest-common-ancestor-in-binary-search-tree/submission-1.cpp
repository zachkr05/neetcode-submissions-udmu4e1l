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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (true){
            int root_num = root->val;
            int p_num = p->val;
            int q_num = q->val;

            if (p_num>root_num && q_num>root_num){
                root = root->right;
            }

            else if (p_num<root_num && q_num<root_num){
                root = root->left;
            }

            else{
                return root;
            }
        }
    }
};
