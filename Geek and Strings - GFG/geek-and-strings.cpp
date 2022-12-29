//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    class Tri{
        public:
        Tri *a[26];
        int cnt;
        Tri(){
            for(int i=0;i<26;i++){
                this->a[i] = NULL;
            }
            this->cnt = 0;
        }
        void add(Tri *root, string s){
            Tri *t = root;
            for(auto x:s){
                int idx = x-'a';
                if(t->a[idx] == NULL) t->a[idx] = new Tri();
                t->a[idx]->cnt++;
                t = t->a[idx];
            }
        }
        int get(Tri *root, string s){
            Tri *t = root;
            for(auto x:s){
                int idx = x-'a';
                if(t->a[idx] == NULL) return 0;
                t = t->a[idx];
            }
            return t->cnt;
        }
    };
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        Tri *root = new Tri();
        Tri tr;
        for(int i=0;i<N;i++){
            tr.add(root, li[i]);
        }
        vector<int> ans;
        for(int i=0;i<Q;i++){
            int cur = tr.get(root, query[i]);
            ans.push_back(cur);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends