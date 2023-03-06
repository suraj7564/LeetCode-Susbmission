//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<pair<int, int>> s1;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s1.empty()) return -1;
           return s1.top().second;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           int ans = -1;
           if(!s1.empty()){
               ans = s1.top().first;
               s1.pop();
           }
           return ans;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s1.empty()){
               s1.push({x, x});
           }
           else{
               s1.push({x, min(x, s1.top().second)});
           }
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends