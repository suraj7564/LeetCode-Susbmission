//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        stack<long long> s1;
        long long ans=0;
        for(int i=0;i<n;i++){
            while(!s1.empty()&&arr[s1.top()]<arr[i]){
                long long cur=arr[s1.top()];
                s1.pop();
                if(s1.empty()){
                    break;
                }
                long long diff=i-s1.top()-1;
                ans+=(min(arr[s1.top()],arr[i])-cur)*diff;
            }
            s1.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends