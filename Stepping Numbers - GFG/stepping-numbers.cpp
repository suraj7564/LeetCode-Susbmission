//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        queue<int> q;
        map<int, int> mp;
        for(int i=0;i<10;i++){
            q.push(i);
            mp[i] = 1;
        }
        int cnt = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t > m) continue;
            if(t>=n) cnt++;
            //cout<<t<<" ";
            int x = t%10;
            if(x-1>=0){
                int num = t*10 + x - 1;
                if(mp[num] != 1){
                    mp[num] = 1;
                    q.push(num);
                }
            }
            if(x+1<10){
                int num = t*10 + x + 1;
                if(mp[num] != 1){
                    mp[num] = 1;
                    q.push(num);
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends