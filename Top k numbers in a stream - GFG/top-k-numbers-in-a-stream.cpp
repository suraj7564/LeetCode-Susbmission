// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    struct cmp{
        bool operator() (pair<int,int> a,pair<int,int> b){
           if(a.first == b.first)
                return (a.second > b.second);
           return a.first<b.first;
        }
    };
    vector<int> kTop(int a[], int n, int k) 
    { 
        vector<int> ans;
        unordered_map<int,int> m;   
        for(int i=0;i<n;i++){
            m[a[i]]++;
            priority_queue<pair<int,int> , vector<pair<int,int>> ,cmp > pq;
            for(auto x:m){
                pq.push({x.second,x.first});
            }
            int p=k;
            while(p-->0&&!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
           // pq.clear();
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends