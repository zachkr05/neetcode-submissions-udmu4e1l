class MyHashMap {

private:
    struct ListNode{
        int key;
        int value;
        ListNode* next;
        ListNode(int k=-1, int v=-1, ListNode* n=nullptr){
            key = k;
            value = v;
            next = n;
        }
    };

    vector<ListNode*> map;
    int hash(int key){
        return key % map.size();
    }


public:
    MyHashMap() {
        map.resize(1000);
        for (auto& bucket : map){
            bucket = new ListNode(0);
        }
        
    }
    
    void put(int key, int value) {
        ListNode* cur = map[hash(key)];
        while(cur->next){
            if(cur->next->key == key){
                cur->next->value = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new ListNode(key, value);
    }
    
    int get(int key) {
        ListNode* cur = map[hash(key)]->next;
        while(cur){
            if(cur->key == key){
                return cur->value;
            }
            cur = cur->next;
        }
        return -1;
        
    }
    
    void remove(int key) {
        ListNode* cur = map[hash(key)];
        while(cur->next){
            if(cur->next->key == key){
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */