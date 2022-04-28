class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        for(int i=0;i<arr[0].length();i++){
            for(int j=0;j<n;j++){
                if(i>=arr[j].length()||arr[j][i]!=arr[0][i]) return arr[0].substr(0,i);
            }
        }
        return arr[0];
    }
};