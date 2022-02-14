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
	    queue<string> q;
	    q.push("1");
	    q.push("2");
	    n--;
	    while(n-->0){
	        auto t=q.front();
	        q.pop();
	        q.push(t+"1");
	        q.push(t+"2");
	    }
	    cout<<q.front()<<endl;
	}
	return 0;
}