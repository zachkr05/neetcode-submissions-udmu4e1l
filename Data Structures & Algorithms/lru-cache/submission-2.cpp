
class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int value) : key(key), val(value), prev(nullptr), next(nullptr) {}
};


class LRUCache {


private:

    int _capacity;
    unordered_map<int, Node*> _cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev; // Should be left's ptr
        prev->next = node->next;
        node->next->prev = prev;
    }

    //Insert on the far right.
    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:

    LRUCache(int capacity) {
        this->_capacity = capacity;
        _cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
        right->next = nullptr;
        left->prev = nullptr;
    }
    
    int get(int key) {

        if (_cache.find(key) != _cache.end()){
            Node* node = _cache[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        

        //Update cache this way to be MRU for this node
        if(_cache.find(key) != _cache.end()){
            Node* node = _cache[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        //Put the ptr on the right left
        Node* node = new Node(key, value);
        _cache[key] = node;
        insert(node);
        
        
        //Check if we exceed capacity:
        if(_cache.size() > _capacity){
            //Remove LRU index i.e index on the far right
            Node* lru = left->next;
            remove(lru);
            _cache.erase(lru->key);
            delete lru;
            
        }
    }
};
