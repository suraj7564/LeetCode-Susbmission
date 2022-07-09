class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
		
        deque<int> dq;
        dq.push_back(nums[0]);
		
        for (int i = 1; i < n; i++) {      
            int curMax = dq.front();       
            nums[i] += curMax;
            if (i - k >= 0 && dq.front() == nums[i - k])     
                dq.pop_front();
            while (!dq.empty() && nums[i] > dq.back())        
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        return nums[n-1];
    }
};