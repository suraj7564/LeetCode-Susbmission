//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
        int a = x, b = y;
        set<int> s1;
        while(x){
            s1.insert(x);
            x /= 2;
        }
        int lca = y;
        while(y){
            if(s1.find(y) != s1.end()){
                lca = y;
                break;
            }
            y /= 2;
        }
        int cnt = 0;
        while(a != lca){
            cnt++;
            a /= 2;
        }
        while(b != lca){
            cnt++;
            b /= 2;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends