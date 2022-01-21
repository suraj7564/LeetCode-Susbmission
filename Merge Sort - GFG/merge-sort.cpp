// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int l1=m-l+1;
         int l2=r-m;
         int a[l1];
         int b[l2];
         for(int i=0;i<l1;i++){
             a[i]=arr[l+i];
         }
         for(int i=1;i<=l2;i++){
             b[i-1]=arr[m+i];
         }
         int x=0,y=0;
         int idx=l;
         while(x<l1&&y<l2){
             if(a[x]<=b[y]){
                 arr[idx++]=a[x++];
             }
             else{
                 arr[idx++]=b[y++];
             }
         }
         while(x<l1){
             arr[idx++]=a[x++];
         }
         while(y<l2){
             arr[idx++]=b[y++];
         }
        //  cout<<"a:";
        //  for(int i=0;i<l1;i++){
        //      cout<<a[i]<<" ";
        //  }
        //  cout<<endl<<"b:";
        //  for(int i=0;i<l2;i++){
        //      cout<<b[i]<<" ";
        //  }
        //  cout<<endl;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends