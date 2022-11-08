//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int total = 0;
        for(int i=0;i<N;i++){
            total ^= Arr[i];
        }
        // code here
        long long int st = 0;
        for(int i=0;i<64;i++){
            if(total & (1LL<<i)){
                st = (1LL<<i);
                break;
            }
        }
        long long int first = 0;
        for(int i=0;i<N;i++){
            if(Arr[i] & st){
                first ^= Arr[i]; 
            }
        }
        long long int second = total ^ first;
        long long int x = max(first, second), y = min(first, second);
        return {x, y};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends