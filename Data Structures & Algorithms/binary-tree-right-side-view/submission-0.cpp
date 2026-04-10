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
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;

        //Start BFSing through the queue
        while(!q.empty()){

            int rightSide = -1; // response for current layer
            int q_len = q.size(); 
            cout<<"a";
            //loop thru each node in the current queue
            for(int i = 0; i<q_len; i++){

                //get the actual node
                TreeNode* front = q.front();
                q.pop();
                if(front){ // if there exists some node
                    q.push(front->left);
                    q.push(front->right);
                    rightSide = front->val;
                } 
            }
            if (rightSide != -1){
                res.push_back(rightSide);
            }

        }

        return res;

    }
};
