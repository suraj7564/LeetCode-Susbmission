//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void printPattern(int N)
    {
        // Write Your Code here
        vector<vector<int>> a;
        for(int i=1;i<=N;i++){
            int x = 2, y = N;
            vector<int> cur;
            for(int j=1;j<=N;j++){
                if(j<=i){
                    //cout<<y;
                    cur.push_back(y);
                    y--;
                }
                else{
                    cur.push_back(N+1-i);
                    //cout<<N+1-i;
                }
            }
            a.push_back(cur);
            //cout<<endl;
        }
        
        
        for(int i=0;i<N;i++){
            for(auto x:a[i]){
                cout<<x;
            }
            for(int j=a[i].size()-2;j>=0;j--){
                cout<<a[i][j];
            }
            cout<<endl;
        }
        for(int i=N-2;i>=0;i--){
            for(auto x:a[i]){
                cout<<x;
            }
            for(int j=a[i].size()-2;j>=0;j--){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        
        Solution ob;
        ob.printPattern(N);
        
    }
    return 0;
}
// } Driver Code Ends