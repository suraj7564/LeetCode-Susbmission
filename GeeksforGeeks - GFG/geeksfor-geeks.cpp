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
	    queue<int> q;
	    for(int i=1;i<=n;i++){
	        q.push(i);
	    }
	    while(q.size()>1){
	        int cur=q.front();
	        q.pop();
	        q.pop();
	        q.push(cur);
	    }
	    cout<<q.front()<<endl;
	}
	return 0;
}