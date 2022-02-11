// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution {
public:    
    vector<int> rotation(int n)
    {
        vector<int> ans;
        vector<int> arr(1001,0);
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        int i=1;
        while(!q.empty()){
            for(int j=0;j<i;j++){
                int t=q.front();
                q.pop();
                q.push(t);
            }
            int x=q.front();
            if(arr[x]) return {-1};
            arr[x]=i;
            q.pop();
            i++;
        }
        for(int i=1;i<=n;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin >> n;
        vector<int > ans;
        ans = obj.rotation(n);
        for(int i:ans)
            cout<< i << " ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends