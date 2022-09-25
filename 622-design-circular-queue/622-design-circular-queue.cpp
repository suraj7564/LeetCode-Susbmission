class MyCircularQueue {
public:
    vector<int> que;
    int l = 0, r = 0, k; 
    MyCircularQueue(int k) {
        que = vector<int>(100000, -1);
        this->k = k;
    }
    bool enQueue(int value) {
        if (!isFull()) {
            que[r++ % k] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            que[l++ % k] = -1;
            return true;
        }
        return false;
    }
    
    int Front() {
        return que[l % k];
    }
    
    int Rear() {
        return que[(r - 1 + k) % k];
    }
    
    bool isEmpty() {
        return r - l == 0;
    }
    
    bool isFull() {
        return r - l == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */