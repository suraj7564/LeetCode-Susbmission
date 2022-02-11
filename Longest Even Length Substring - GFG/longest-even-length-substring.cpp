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
        string s;
        cin>>s;
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> pre;
            int cnt=0;
            for(int j=i;j<n;j++){
                cnt+=(s[j]-'0');
                pre.push_back(cnt);
                if(pre.size()%2==0){
                    int sz=pre.size();
                    if(pre[sz/2-1]==(pre[sz-1]-pre[sz/2-1])){
                        ans=max(ans,sz);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}