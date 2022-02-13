// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    
    long long int countOfSubstringWithKOnes(string S, int K){
        long long ans=0;
        unordered_map<long long ,long long> m;
        long long sum=0;
        m[0]=1;
        for(int i=0;i<S.length();i++){
            sum+=S[i]=='1';
            if(m.count(sum-K)) ans+=m[sum-K];
            m[sum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       int k;
       cin >> s >> k;
       Solution ob;
       cout << ob.countOfSubstringWithKOnes(s, k) << endl;
    }
return 0;
}

  // } Driver Code Ends