//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int a[], int b[], int l1, int l2)
    {
        
        int i = 0, j = 0;
        int suma = 0, sumb = 0;
        int ans = 0;
        while(i < l1 && j < l2){
            if(a[i] < b[j]){
                suma += a[i];
                i++;
            }
            else if(a[i] > b[j]){
                sumb += b[j];
                j++;
            }
            else{
                ans += max(suma, sumb) + a[i];
                i++, j++;
                suma = 0, sumb = 0;
            }
        }
    
        while(i < l1){
            suma += a[i];
            i++;
        }
        
        while(j < l2){
            sumb += b[j];
            j++;
        }
        return ans + max(suma, sumb);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends