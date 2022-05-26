// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    long long noOfNumbers(long long n) {
        // code here
        long long arr[] = {2,3,5,7};
        long long sum = 0;
        for(int i=0;i<4;i++){
            sum += (n/arr[i]);
            for(int j=i+1;j<4;j++){
                sum -= (n/(arr[i]*arr[j]));
                for(int k=j+1;k<4;k++){
                    sum += (n/(arr[i]*arr[j]*arr[k]));
                    for(int l=k+1;l<4;l++){
                        sum -= (n/(arr[i]*arr[j]*arr[k]*arr[l]));
                    }
                }
            }
        }
        
        return n-sum;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfNumbers(N) << endl;
    }
    return 0;
}  // } Driver Code Ends