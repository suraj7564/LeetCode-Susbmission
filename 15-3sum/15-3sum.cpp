class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        int K = 0;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0&&arr[i]==arr[i-1]) continue;
            int j=i+1,k=n-1;
            int need = K-arr[i];
            while(j<k){
                if(arr[j]+arr[k]==need){
                    ans.push_back({arr[i],arr[j],arr[k]});
                    while(j+1<k&&arr[j]==arr[j+1]) j++;
                    while(k-1>j&&arr[k]==arr[k-1]) k--;
                    j++,k--;
                }
                else if(arr[j]+arr[k]<need){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};