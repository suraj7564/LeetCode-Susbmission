// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
    vector<pair<int,int>> cur;
    for(int i=0;i<n;i++){
        cur.push_back({p[i].first,p[i].second});
    }
    sort(cur.begin(),cur.end());
    vector<int> dp(n,1);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(cur[j].second<cur[i].first){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    return ans;
}