class MyHashSet {
public:
    unordered_set<int> s1;
    MyHashSet() {
        
    }
    
    void add(int key) {
        s1.insert(key);
    }
    
    void remove(int key) {
        s1.erase(key);
    }
    
    bool contains(int key) {
        return s1.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */