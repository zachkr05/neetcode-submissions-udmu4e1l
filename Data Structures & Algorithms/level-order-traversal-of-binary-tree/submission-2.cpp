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
    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>> res;

        //q = {(1,2,3)}
        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){

            vector<int> level;
            int curr_size = q.size();



            for (int i = 0; i<curr_size; i++){ //0 

                TreeNode* curr_node = q.front();
                q.pop();

                if (curr_node){
                    level.push_back(curr_node->val);
                    q.push(curr_node->left);
                    q.push(curr_node->right);

                } 
            }

            if (!level.empty()){
                res.push_back(level);
            }
            

        }

        return res;
        
    }
};
