/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {


private:

    unordered_map<Node*, Node*> memory;

    Node* dfs(Node* node){

        if (node == nullptr){
            return nullptr;
        }

        if (memory.contains(node)){
            return memory[node];
        }

        Node* new_node = new Node{node->val};


        memory[node] = new_node;

        for (Node* nei : node->neighbors){
            Node* temp = dfs(nei);
            new_node->neighbors.push_back(temp);
        }

        return new_node;


    }


public:
    Node* cloneGraph(Node* node) {

        return dfs(node);
        
    }
};
