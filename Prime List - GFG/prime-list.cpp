//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
    int dp[100001];
    bool isPrime(int n){
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        if(dp[n]!=-1) return dp[n];
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                return dp[n]=0;
            }
        }
        return dp[n]=1;
    }

public:

    Node *primeList(Node *head){
        memset(dp,-1,sizeof(dp));
        Node* temp=head;
        while(temp){
            if(!isPrime(temp->val)){
                int a=0,b=0,num=temp->val;
                for(int i=num; i>=2; i--){
                    if(isPrime(i)){
                        a=i;
                        break;
                    }
                }
                for(int i=num; i<1e5+1; i++){
                    if(isPrime(i)){
                        b=i;
                        break;
                    }
                }
                if(a!=0 && b!=0){
                    if(abs(num-a)<abs(num-b)){
                        temp->val=a;
                    }
                    else if(abs(num-a)>abs(num-b)){
                        temp->val=b;
                    }
                    else{
                        if(a<b){
                            temp->val=a;
                        }
                        else{
                            temp->val=b;
                        }
                    }
                }
                else if(a!=0){
                    temp->val=a;
                }
                else{
                    temp->val=b;
                }
            }
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends