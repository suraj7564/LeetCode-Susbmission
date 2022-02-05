// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int papa[100001];
    int rank[100001];
    void set(){
        for(int i=0;i<100001;i++){
            papa[i]=i;
            rank[i]=0;
        }
    }
    int findpapa(int x){
        if(papa[x]==x) return x;
        return papa[x]=findpapa(papa[x]);
    }
    void check(int x,int y){
        x=findpapa(x);
        y=findpapa(y);
        if(rank[x]>=rank[y]){
            papa[y]=x;
            rank[x]++;
        }
        else{
            papa[x]=y;
            rank[y]++;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set();
        vector<vector<int>> e;
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                e.push_back({x[1],x[0],i});
               // cout<<i<<" "<<x[0]<<" "<<x[1]<<endl;
            }
        }
        sort(e.begin(),e.end());
        int ans=0;
        for(auto x:e){
            if(findpapa(x[1])!=findpapa(x[2])){
                check(x[1],x[2]);
                ans+=x[0];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends