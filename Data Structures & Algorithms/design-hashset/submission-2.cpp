class MyHashSet {

private:
    struct listNode{
        int key;
        listNode* next;
        listNode(int k) : key(k), next(nullptr) {};
    };
    vector<listNode*> set;

    int hash(int key){
        return key%set.size();
    }

public:
    MyHashSet() {
        set.resize(10000);
        for (auto& bucket : set){
            bucket = new listNode(0);
        }
    }
    
    void add(int key) {
        int idx = hash(key);
        listNode* curr = set[idx];
        while(curr->next){
            if(curr->next->key == key){
                return;
            }
            curr = curr->next;
        }
        curr->next = new listNode(key);
    }
    
    void remove(int key) {
        listNode* curr = set[hash(key)];
        while(curr->next){
            if (curr->next->key == key){
                listNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        listNode* curr = set[hash(key)];
        while(curr->next){
            if (curr->next->key == key){
                return true;
            }
            curr = curr->next;
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */