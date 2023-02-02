//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> v,v1;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0) v1.push_back(arr[i]);
	        else v.push_back(arr[i]);
	    }
	    int j=0, k = 0;
	    int x=v.size();
	    for(int i=0;i<v.size();i++){
	        arr[j]=v[i];
	        j++;
	        if(k<v1.size()){
	            arr[j]=v1[i];
	            k++,j++;
	        }
	    }
	    for(;k<v1.size();k++){
	        arr[j] = v1[k];
	        j++;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends