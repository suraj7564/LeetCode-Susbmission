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
	    int n,k;
	    cin>>n>>k;
	    deque<int> dq;
        for(int i = 1; i <= n; i++){
            dq.push_back(i);
        }
        int i = 1; 
        while(dq.size() > 1){
            if(i % 2 != 0){
                for(int j = 0; j < k; j++){
                    if(dq.size() == 1){
                        break;
                    }
                    dq.pop_front();
                }
                i++;
            }
            else{
                for(int j = 0; j < k; j++){
                    if(dq.size() == 1){
                        break;
                    }
                    dq.pop_back();
                }
                i++;
            }
        }
        cout<<dq.front()<<endl;
	}
	return 0;
}