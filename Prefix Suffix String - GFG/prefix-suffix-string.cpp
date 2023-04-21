//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Trie{
    public:
    Trie *a[26];
    bool isEnd;
    Trie(){
        for(int i=0;i<26;i++){
            this -> a[i] = NULL;
        }
        this->isEnd = false;
    }
    void insert(string s, Trie *root){
        Trie *temp = root;
        for(auto x:s){
            if(temp -> a[x - 'a'] == NULL){
                temp -> a[x - 'a'] = new Trie();
            }
            temp = temp -> a[x - 'a'];
        }
        temp -> isEnd = true;
    }
    bool search(string s, Trie *root){
        Trie *temp = root;
        for(auto x:s){
            if(temp -> a[x - 'a'] == NULL){
                return false;
            }
            temp = temp -> a[x - 'a'];
        }
        return true;
    }
};
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Trie *root = new Trie();
        Trie *root1 = new Trie();
        Trie tr, tr1;
        for(int i=0;i<s1.size();i++){
            string a = s1[i], b = s1[i];
            reverse(b.begin(), b.end());
            tr.insert(a, root);
            tr1.insert(b, root1);
        }
        int ans = 0;
        for(int i=0;i<s2.size();i++){
            string a = s2[i], b = s2[i];
            reverse(b.begin(), b.end());
            if(tr.search(a, root) || tr1.search(b, root1)){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends