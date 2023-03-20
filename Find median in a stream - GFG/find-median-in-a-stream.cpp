//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<double> pq1, pq2;
    void insertHeap(int &x)
    {
        pq1.push(x);
        pq2.push(-pq1.top());
        pq1.pop();
        if(pq2.size() > pq1.size()){
            pq1.push(abs(pq2.top()));
            pq2.pop();
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(pq1.size() > pq2.size()){
            return pq1.top();
        }
        return (pq1.top() + -pq2.top())/2.0;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends