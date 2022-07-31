class NumArray {
public:
    vector<int> t,a;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        a.assign(n, 0);
        t.assign(n, 0);
        for(int i=0;i<n;i++){
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int x = val;
        val -= a[index];
        a[index] = x;
        for(int i = index; i < n ; i = i|(i+1)){
            t[i] += val;
        }
    }
    
    int sumRange(int left, int right) {
        return sumRange(right)-sumRange(left-1);
    }
    
    int sumRange(int r){
        int sum = 0;
        for(;r>=0;r = (r&(r+1))-1){
            sum += t[r];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */