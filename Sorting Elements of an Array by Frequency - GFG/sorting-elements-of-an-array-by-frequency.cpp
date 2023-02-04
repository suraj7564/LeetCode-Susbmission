#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define speed ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
#define endl "\n"
#define mod 1000000007

int main()
 {
 	speed;
	//code
	int t;
	cin>>t;
	while(t-->0){
	    int n, x;
	    cin>>n;
	    map<int, int> m;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        m[x]++;
	    }
	    vector<pair<int, int>> a;
	    for(auto x:m){
	        a.push_back({x.first, x.second});
	    }
	    sort(a.begin(), a.end(), [&](pair<int, int>& p, pair<int, int>& q){
	        if(p.second == q.second){
	            return p.first < q.first;
	        }
	        return p.second > q.second;
	    });
	    for(int i=0;i<a.size();i++){
	        for(int j=0;j<a[i].second;j++)
	            cout<<a[i].first<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}