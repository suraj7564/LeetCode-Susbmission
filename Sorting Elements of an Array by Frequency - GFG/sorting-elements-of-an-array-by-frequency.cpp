#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define speed ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
#define endl "\n"
#define mod 1000000007

int main()
 {
 	speed;
	int t;
	cin>>t;
	while(t-->0){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        m[a[i]]++;
	    }
	    sort(a.begin(),a.end(),[&](int a,int b){
	        if(m[a]==m[b]){
	            return a<b;
	        }
	        return m[a]>m[b];
	    });
	    for(auto x:a){
	        cout<<x<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}