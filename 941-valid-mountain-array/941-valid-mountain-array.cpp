class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool b = false;
        if(arr.size()<3||arr[1]<=arr[0]) return false;
        int n=arr.size();
        int j=-1;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                j=i;
                break;
            }
            if(arr[i]==arr[i-1]) return false;
        }
        if(j==-1) return false;
        for(int i=j;i<n;i++){
            if(arr[i]>=arr[i-1]) return false;
        }
        
        return true;
    }
};