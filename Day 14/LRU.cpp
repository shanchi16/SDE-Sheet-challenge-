class LRUCache {
public:
    class node{
        public:
        node* next;
        node* prev;
        int key; int value;
        node(int _key, int _val){
            key = _key;
            value = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            int valuee = temp->value;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return valuee;

        }
        else return -1;
    }

    void addNode(node* tempp){
        node* t = head->next;
        tempp->next = t;
        tempp->prev = head;
        head->next = tempp;
        t->prev = tempp;
    }

    void deleteNode(node* tempp){
        node* tempPrev = tempp->prev;
        node* tempNext = tempp->next;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
            
        }
        if(cap == mp.size()){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */