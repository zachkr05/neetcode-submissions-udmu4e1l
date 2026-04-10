/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //Copy the list --> make a map from old node to new node
        
        Node* dummy = head;
        unordered_map<Node*, Node*> _map;

        while(dummy != nullptr){
            _map[dummy] = new Node(dummy->val);
            dummy = dummy->next;
        }

        // for (const auto& pair: _map){
        //     std::cout << pair.first << ": " << pair.second << std::endl;
        // }
        
        Node* old = head;
        Node* orig = _map[old];
        while(old != nullptr){
            Node* _new = _map[old];
            _new->random = _map[old->random];
            _new->next = _map[old->next];
            old = old->next;
        }

        return orig;
        //

    }
};
