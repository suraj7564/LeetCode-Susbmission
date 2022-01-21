// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(vector<int> cur,int n,int x){
        for(int i=0;i<n;i++){
            int y=i+1;
            if(x==cur[i]||(y+cur[i])==(x+n+1)){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if((cur[i]-i)==(x-n)) return false;
        }
        return true;
    }
    void find(vector<vector<int>>& ans,vector<int>& cur,int curpos,int n){
        if(curpos==n){
            ans.push_back(cur);
            return;
        }
        for(int i=1;i<=n;i++){
            if(isValid(cur,curpos,i)){
                cur[curpos]=i;
                find(ans,cur,curpos+1,n);
                cur[curpos]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> cur(n);
        find(ans,cur,0,n);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends