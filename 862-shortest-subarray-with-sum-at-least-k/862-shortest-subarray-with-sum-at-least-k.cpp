class Solution {
public:
    int shortestSubarray(vector<int>& a, int K) {
        vector<long> A;
        for(auto x:a) A.push_back(x);
        int N = A.size(), res = N + 1;
        deque<long> d;
        for (int i = 0; i < N; i++) {
            if (i > 0)
                A[i] += A[i - 1];
            if (A[i] >= K)
                res = min(res, i + 1);
            while (d.size() > 0 && A[i] - A[d.front()] >= K){
                if(res > i-d.front()){
                    res = i-d.front();
                }
                d.pop_front();
            }
            while (d.size() > 0 && A[i] <= A[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};