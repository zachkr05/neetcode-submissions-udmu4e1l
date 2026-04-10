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

        if(!root){
            return nullptr;
        }

        queue<TreeNode*> _queue;
        _queue.push(root);

        while(!_queue.empty()){
            
            TreeNode* curr = _queue.front();
            _queue.pop();

            TreeNode* temp = curr->left;
            

            swap(curr->left, curr->right);
            if(curr->left) _queue.push(curr->left);
            if(curr->right) _queue.push(curr->right);
        }

        return root;
    }
};
