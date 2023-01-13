//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends


class Solution{
public:
    int minOperations(int *arr,int n)
    {
        int ans = 0;
 
        // max heap
        priority_queue<int> pq;
     
        // Here in the loop we will
        // check that whether the top
        // of priority queue is greater than the upcoming array
        // element. If yes then we calculate the difference.
        // After that we will remove that element and push the
        // current element in queue. And the sum is incremented
        // by the value of difference
     
        for (int i = n - 1; i >= 0; i--) {
            if (!pq.empty() and pq.top() > arr[i]) {
                ans += abs(arr[i] - pq.top());
                pq.pop();
                pq.push(arr[i]);
            }
            pq.push(arr[i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends