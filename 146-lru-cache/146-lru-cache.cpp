class LRUCache {
public:
    class node{
        public:
        int key,val;
        node *next,*prev;
        node(int key,int val){
            this->key = key;
            this->val = val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int,node*> m;
    int sz;
    LRUCache(int capacity) {
        sz = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addNode(node *cur){
        node *temp = head->next;
        cur->next = temp;
        temp->prev = cur;
        head->next = cur;
        cur->prev = head;
    }
    void deleteNode(node *cur){
        node *pre = cur->prev;
        node *nxt = cur->next;
        pre -> next = nxt;
        nxt -> prev = pre;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *cur = m[key];
            int res = cur->val;
            deleteNode(cur);
            addNode(cur);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *cur = m[key];
            m.erase(key);
            deleteNode(cur);
        }
        else if(sz==m.size()){
            node *cur = tail->prev;
            m.erase(cur->key);
            deleteNode(cur);
        }
        node *temp = new node(key,value);
        addNode(temp);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */