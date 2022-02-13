// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<vector<int>> cur;
        for(int i=0;i<N;i++){
            cur.push_back({phy[i],chem[i],math[i]});
        }
        sort(cur.begin(),cur.end(),[&](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                if(a[1]==b[1]){
                    return a[2]<b[2];
                }
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int i=0;
        for(auto x:cur){
            phy[i]=x[0];
            chem[i]=x[1];
            math[i]=x[2];
            i++;
        }
    } 
};

// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends