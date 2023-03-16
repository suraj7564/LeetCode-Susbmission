//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        string ans = string(D, '9');
        int sum = 9 * D;
        if(sum < S) return "-1";
        int cur, diff = sum - S;
        for(int i=0;i<D;i++){
            if(diff <= 0) break;
            if(i == 0){
                cur = min(ans[i] - '1', diff);
            }
            else{
                cur = min(ans[i] - '0', diff);
            }
            ans[i] -= cur;
            diff -= cur;
        }
        int j = -1, k = D - 1;
        for(int i=D-2;i>=0;i--){
            if(ans[i] != '9'){
                j = i, k = i + 1;
                break;
            }
        }
        if(diff > 0 || ans.back() == '0' || j == -1) return "-1";
        
        ans[j]++;
        ans[k]--;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends