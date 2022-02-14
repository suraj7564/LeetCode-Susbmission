// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    int p=0,q=0;
    int ans=0;
    for(auto x:s){
        if(x=='{') p++;
        else q++;
        if(q>p){
            swap(p,q);
            ans++;
        }
    }
    if((p-q)%2) return -1;
    return ans+(p-q)/2;
}