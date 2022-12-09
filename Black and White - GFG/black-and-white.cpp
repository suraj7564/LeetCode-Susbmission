//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool isValid(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}
long long numOfWays(int N, int M)
{
    // write code here
    long long ans = 0, mod = 1e9 + 7, total = (long long)N * (long long)M;
    int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
    int dy[] = {2, -2, -2, 2, 1, -1, -1, 1};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            long long cnt = 0;
            for(int k=0;k<8;k++){
                if(isValid(i+dx[k], j+dy[k], N, M)){
                    cnt++;
                }
            }
            ans = (ans%mod + (total - cnt)%mod)%mod;
        }
    }
    return (ans - total)%mod;
}