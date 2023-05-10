//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int> max_left(N);

        max_left[0] = A[0];

        for(int i=1;i<N;i++){

            max_left[i] = max(max_left[i-1], A[i]);

        }

 

        // compute the minimum element on the right side of each cut

        vector<int> min_right(N);

        min_right[N-1] = A[N-1];

        for(int i=N-2;i>=0;i--){

            min_right[i] = min(min_right[i+1], A[i]);

        }

 

        // count the number of cuts that satisfy the conditions

        int count = 0;

        for(int i=0;i<N-1;i++){

            if(max_left[i] + min_right[i+1] >= K){

                count++;

            }

        }

 

        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends