class Skiplist {
public:
    vector<int> nums;
    Skiplist() {
        nums.assign(200005, 0);
    }
    
    bool search(int target) {
        return nums[target];
    }
    
    void add(int num) {
        nums[num] += 1;
    }
    
    bool erase(int num) {
        if(nums[num]){
            nums[num] -= 1;
            return true;
        }
        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */