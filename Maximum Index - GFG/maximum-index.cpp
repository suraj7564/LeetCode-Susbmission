// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        vector<long long> ans(N+1,INT_MIN);
        for(int i=N-1;i>=0;i--){
            ans[i]=max(ans[i+1],(long long)(A[i]));
        }
        int res=0;
        for(int i=0;i<N;i++){
            int j=i+1,k=N-1;
            int idx=i;
            while(j<=k){
                int mid=(j+k)/2;
                if(ans[mid]>=A[i]){
                    idx=max(idx,mid);
                    j=mid+1;
                }
                else{
                    k=mid-1;
                }
            }
            res=max(res,idx-i);
        }
        return res;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends