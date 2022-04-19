class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int idx = 1;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                arr[idx] = arr[i];
                idx++;
                cnt++;
            }
        }
        return cnt;
    }
};