// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int CountPS(char s[], int n)
{
    //code here
    int cnt = 0;
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,false));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = dp[i][1] = true;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[j-1]==s[j-i]&&dp[j-1][i-2]){
                dp[j][i] = true;
                cnt++;
            }
        }
    }
    return cnt;
}