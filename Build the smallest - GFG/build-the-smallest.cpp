//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string s, int k)
{
    //code here.
    int n = s.length();
    stack<char> s1;
    s1.push(s[0]);
    for(int i=1;i<n;i++){
        while(!s1.empty() && s1.top() > s[i] && k>0){
            k--;
            s1.pop();
        }
        s1.push(s[i]);
    }
    string ans = "";
    while(!s1.empty()){
        ans += s1.top();
        s1.pop();
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() > 0 && k-->0){
        ans.pop_back();
    }
    int i = 0;
    while(ans[i] == '0' && ans.size() > i) i++;
    ans = ans.substr(i);
    if(ans == "") return "0";
    return ans;
}