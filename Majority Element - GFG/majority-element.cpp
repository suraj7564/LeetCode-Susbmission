//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int vote = 0, res = -1;
        for(int i=0;i<size;i++){
            if(vote == 0){
                vote++;
                res = a[i];
                continue;
            }
            if(res == a[i]){
                vote++;
            }
            else{
                vote--;
            }
        }
        int cnt = 0;
        for(int i=0;i<size;i++){
            cnt += res == a[i];
        }
        if(cnt > size/2) return res;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends