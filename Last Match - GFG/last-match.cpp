//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    vector<int> lcp(string s){
        int n = s.length();
        vector<int> z(n, 0);
        int i = 0, j = 1;
        while(j<n){
            if(s[i] == s[j]){
                z[j] = i+1;
                i++, j++;
            }
            else{
                if(i > 0){
                    i = z[i - 1];
                }
                else{
                    j++;
                }
            }
        }
        return z;
    }
    int findLastOccurence(string A,string B){
        //Code Here
        int idx = -1;
        vector<int> z = lcp(B);
        int m = B.length();
        int i = 0, j = 0;
        while(j < A.length()){
            if(A[j] == B[i]){
                i++, j++;
                if(i == m){
                    idx = j - m + 1;
                    i = z[i-1];
                }
            }
            else{
                if(i>0) i = z[i-1];
                else j++;
            }
        }
        return idx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends